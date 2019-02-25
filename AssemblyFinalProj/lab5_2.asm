%include "asm_io.inc"

SECTION .data

err1: db "Wrong number of command line arguments/not single dig.",0,10
err2: db "Argument is less than 2.",0,10
err3: db "Argument is greater than 9.",0,10
err4: db "Argument is not a single digit.",0,10
begin: db " initial configuration:",0,10
end: db "  final configuration:",0,10
value: dd 0,0,0,0,0,0,0,0,0
Xstring: db "XXXXXXXXXXXXXXXXXXXXXXX",0,10

SECTION .bss
line: resd 50
N: resd 1
i: resd 1
pegs: resd 1
change: resd 1

SECTION .text
   global  asm_main

showp:
   enter 0,0
   pusha
  
   mov ebx, [ebp+8]   
   mov ecx, [ebp+12]  
   add esp, 8
   mov edx, dword 4
   mov eax, ecx
   sub eax, 1
   mul edx
   add ebx, eax 
   mov edx, dword 0

   Pyramid:           
   pusha                
   push ebx  
   call line1
   sub ebx, 4
   add edx, 1
   cmp edx, ecx  
   jb Pyramid
   mov eax, Xstring
   call print_string
   call print_nl
   add esp, 4 
  
   popa                  ; restore all registers
   mov eax, 0            ; return back to caller
   leave                     
   ret

line1: 

   enter 0,0                ; setup routine
   pusha                    ; save all registers
   mov ebx, [ebp+8]         ; address of N1
   mov ecx, dword [ebx]     ; ecx=N1
   mov [N], ecx             ; remember N
   mov ecx, line            ; pointer to line

   mov edi, N
   mov esi, 0
   LOOP: 
     mov ebx, 11
     sub ebx, dword [edi]    ; ebx=number of spaces needed -- 12-N
     mov eax, 0              ; counter
     L11: cmp eax, ebx
     jae L12
     mov [ecx], byte ' '
     inc eax
     inc ecx
     jmp L11 
     ; now we need N pluses
     L12: mov eax, 0            ; counter
     L13: cmp eax, dword [edi]
     jae L14
     mov [ecx], byte 'o'
     inc eax
     inc ecx
     jmp L13
     ; now we need |
     L14: mov [ecx], byte '|'
     inc ecx
     ; now we need N pluses
     mov eax, 0            ; counter
     L15: cmp eax, dword [edi]
     jae L16
     mov [ecx], byte 'o'
     inc eax
     inc ecx
     jmp L15
     ; now we need 12-N spaces, we remembered the value in ebx
     L16: mov eax, 0            ; counter
     L17: cmp eax, ebx
     jae LOOP_END
     mov [ecx], byte ' '
     inc ecx
     inc eax
     jmp L17
 LOOP_END:

   mov eax, line
   call print_string
   call print_nl
   popa
   leave
   ret

swap:
  enter 0,0
  pusha
 
  mov ecx, [ebp+12]                              
  mov edx, [ebp+8]

  mov eax, [ecx]
  mov ebx, [edx]

  mov [ecx], ebx
  mov [edx], eax

  popa
  leave
  ret 

sorthem:
  enter 0,0
  pusha
  
  mov ecx, [ebp+12]  ;; [ebp+8] ; Stores numebr of pegs
  mov ebx, [ebp+8] ; Pointer to array 
  mov eax, ecx
  cmp ecx, 1 ; Compares n to 1
  je sorthem_end  

  add ebx, 4  ; Gives A + 4
  dec ecx  ; Gives n - 1
  push ecx 
  push ebx
  call sorthem
  add esp, 8
  
  sub ebx, 4  ; Returns to A
  mov eax, ebx 
  add eax, 4  ; Gives A + 4
  
  mov [i], dword 0  ; Stores value of i
  mov [change], dword 0
  loop:
  cmp ecx, [i]  ; Compares i and n - 1
  je loop_end  

  mov edx, [eax]

  cmp [ebx], edx  ; Compares A and A+4
  ja loop_end

  swapval:
  push eax
  push ebx
  call swap
  add esp, 8
  add ebx, 4
  add eax, 4
  mov [change], dword 1
  add [i], dword 1 
  jmp loop


  loop_end:
  cmp [change], dword 1
  jne sorthem_end
  pusha
  push dword [pegs]
  push dword value
  call read_char
  call showp
  call print_nl
  add esp, 8
  popa


  sorthem_end:
  popa   
  leave 
  ret


asm_main:
   enter 0,0
   pusha

   mov ecx, dword [ebp+8]   ; argc
   cmp ecx, dword 2         ; argc should be 2
   jne ERR1

   mov ebx, dword [ebp+12]  ; address of argv[]
   mov ecx, dword [ebx+4]   ; argv[1]
   
   cmp byte[ecx+1], byte 0
   jne ERR4

   cmp byte [ecx], '2'
   jb ERR2

   cmp byte [ecx], '9'
   ja ERR3 
   
   mov edx, dword 0
   mov dl, byte[ecx]
   sub dl, '0'
   mov ebx, edx
   mov [pegs], ebx
   mov ecx, value

   push ebx
   push ecx
   call rconf
   
   mov eax, begin
   call print_string
   call print_nl
   call showp
   call print_nl
   call sorthem
   call read_char
   mov eax, end
   call print_string
   call print_nl
   call showp
   call print_nl

   add esp, 8

   jmp asm_main_end

   ERR1:
   mov eax, err1
   call print_string
   jmp asm_main_end

   ERR2:
   mov eax, err2
   call print_string
   jmp asm_main_end

   ERR3:
   mov eax, err3
   call print_string
   jmp asm_main_end

   ERR4:
   mov eax, err4
   call print_string
   jmp asm_main_end


 asm_main_end:
   popa                  ; restore all registers
   leave                     
   ret

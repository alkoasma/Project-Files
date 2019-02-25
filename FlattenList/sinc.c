#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sinc(double x);
double comph (int N);
double comprho (double x , double a , double b);
double complambda (double x , double h , double a , double b , int j );
void wj (double x , double a , double b , int N , double *w );



extern void wj(double x, double a, double b, int N, double *w);

int main(int argc, char **argv) {
  if (argc != 5) {
    printf("\n Usage sinc N  a b x \n");
    return 1;
  }
  int    N = atoi(argv[1]);
  double a = atof(argv[2]);
  double b = atof(argv[3]);
  double x = atof(argv[4]);

  double w[2 * N + 1];
  wj(x, a, b, N, w);
  for (int i = 0; i < 2*N+1; i++)
    printf("% 3i  % e\n", i, w[i]);
  return 0;
}



/* int main(){
    double num;
    double ans;
    printf("Your number is: ");
    scanf("%lf", &num);
    ans = sinc(num);
    printf("Answer is %f",ans);
    return 0;
} */

double sinc(double x){
    double sincx;
    sincx = sin(M_PI*x)/(M_PI*x);
    if (x != 0)
        return sincx;
    if (x == 0)
        return 1;
}   



/*int main(){
    int N = 7;
    double ans;
    ans = comph (N);
    printf("%f",ans);
    
}*/

double comph (int N){
    double h;
    h = M_PI/sqrt(2*N);
    return h;
}



/*int main(){
    double ans;
    ans = comprho (2 , 3 , 4);
    printf("%f",ans);

}*/

double comprho (double x , double a , double b ){
    double rho;
    rho = (x - a)/(b - x);
    return rho;

}



/* int main(){
    double ans;
    ans=complambda(9,521,32,7.5,838);
    printf("This is %f",ans);
}*/

double complambda (double x , double h , double a , double b , int j ){
    double lambda;
    lambda = (sinc(log(comprho(x,a,b))) - j*h)/h;
    return lambda;
}


void wj (double x , double a , double b , int N , double *w ){
    int j;
    double sum1 = 0, sum2=0, value1 = 0, value2 = 0;
    int k=1;
    double h = comph (N);
    for(j = (- N + 1); j<=N; j++){
        value1 = complambda(x,h,a,b,j)/(1 + pow(M_E,(j*h))) + sum1;
        sum1 = value1;
    }
    
    w[0]=(1 + pow(M_E,(-N*h))) * ((1/(1 + comprho (x,a ,b))) - value1);

    for(j = (-N+1); j<=(N-1); j++){
        w[k] = complambda(x,h,a,b,j);
        k = k + 1;
    }

    for(j = - N; j<=(N-1); j++){
        value2 = ((M_E,j*h)*complambda(x,h,a,b,j))/(1 + pow(M_E,(j*h))) + sum2;
        sum2 = value2;
    }
    
    w[k]=(1 + pow(M_E,(-N*h))) * ((comprho (x,a,b)/(1 + comprho (x,a,b))) - value2);

}

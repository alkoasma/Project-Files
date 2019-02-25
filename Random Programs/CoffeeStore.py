#The program was made to be more user friendly with the options given.

#A class "CoffeeKind" is created and it has two parameters, the price and inventory.
#This allows us to create different kinds of coffee and store the information
class CoffeeKind(object):
      def __init__(self, price, inventory):
        self.price = price
        self.inventory = inventory

#A class "CustomerPruchase" is created to keep track of the customer's cart and their total pay.
class CustomerPurchases(object):
      def __init__(self, finalpay, cart):
        self.finalpay = finalpay
        self.cart = cart

#We define initial parameters using the class above to keep track of the customer's purchses below
CustomerPurchases.finalpay = 0
CustomerPurchases.cart = []

#We assign different kinds of coffee a price and set their inventory level below. (Price, Inventory)
Arabica = CoffeeKind(10, 5)
Robusta = CoffeeKind(8, 1)
Liberica = CoffeeKind(12, 0)

print("\n\nThe initial inventory of the each of the coffee bean bags can be found below:\n\n")
print("Arabica Beans: " + str(Arabica.inventory) + "\n\nRobusta Beans: " + str(Robusta.inventory) + "\n\nLiberica Beans: " + str(Liberica.inventory))
input("\n\nPress enter to go into the store:\n\n")

#This is where the user interface starts
print("Hello, welcome to Coffeetopia!\n")

print("We offer a variety of coffee beans.")

#FindChoice() is a function used to give the program the CoffeeKind based on the customer's choice
#If the customer enters a wrong value, it will recursively call itself
def FindChoice():
    Number = input("\nPlease enter the number corresponding to the coffee beans you would like:\n\n")
    if Number == '1':
        Kind = 'Arabica'
        return Kind
    elif Number == '2':
        Kind = 'Robusta'
        return Kind
    elif Number == '3':
        Kind = 'Liberica'
        return Kind
    else:
        FindChoice()

#Finds the roast perference based on the customers choice during the user interface
#If the customer enters a wrong value, it will recursively call itself
def FindRoast():
    Roast = input("\nPlease enter the number corresponding to the roast you would perfer:\n\n1. Light\n\n2. Medium\n\n3. Dark roast.\n\n")
    if Roast == '1':
        Roast = 'Light'
        return Roast
    if Roast == '2':
        Roast = 'Medium'
        return Roast
    if Roast == '3':
        Roast = 'Dark'
        return Roast
    else:
        FindRoast()

#Finds the grind perference based on the customers choice during the user interface
#If the customer enters a wrong value, it will recursively call itself
def FindGrind():
    Grind = input("\nPlease enter the number corresponding to the coffee grind you would prefer:\n\n1. Whole Beans (Not grinded)\n\n2. Fine grind\n\n3. Coarse grind\n\n")
    if Grind == '1':
        Grind = "Whole"
        return Grind
    if Grind == '2':
        Grind = 'Fine'
        return Grind
    if Grind == '3':
        Grind = 'Course'
        return Grind
    else:
        FindGrind()
    
#This is the function that does the computations based on the inventory and the price of the product.
def compute(beans):
    ###################################################################################
    if int(eval(beans).inventory) == 0: #If there is no inventory, we display a message, and give the options below.
        print("\nSorry, this kind of coffee beans is currently unavailable!\n\n")
        ifempty = input("Please press:\n\n1. To go back to the main menu\n\n2. To exit Coffeetopia\n\n")
        if ifempty == '1':
            main()
            return 0 
        else:
            print("\nThank you for visiting our site!\n\nSee you next time :)")
            return 0
    ####################################################################################
    Roast = FindRoast() 
    Grind = FindGrind()
    ####################################################################################
    print("\nThe price of a 500g bag of " + str(beans) + " coffee is " + str(eval(beans).price) + " dollars\n") #Gives the customer the price  
    pay = int(eval(beans).price) 
    ####################################################################################
    Number = str(input("Would you like to add the beans to your cart?\n\n1. Yes\n\n2. No\n\n")) #Allows the customer the option of adding the beans or not
    product = Grind + " " + Roast + " Roast " + beans + " Beans"  #Produces final product name
    if Number == '1':
        CustomerPurchases.cart.append(product) #Adds the product to the cart/list created at the top 
        CustomerPurchases.finalpay = pay #The price the customer would have to pay at chekout
    elif Number == '2': #This option proceeds to give the customer the option to leave or stay if they did not want they coffee beans
        Number = input("\nWould you like to:\n\n1. Continue shopping with us\n\n2. Leave Coffeetopia\n\n")
        if Number == 1:
            main()
        else:
            print("\nThank you for visiting our site!\n\nSee you next time :)")
            return 0
    ####################################################################################
    NumberCorrect = 0
    #For a customer that added something to their cart
    while(NumberCorrect == 0):  #Asks for input until either 1 or 2 is chosen below
        Number = input("\nWould you like to:\n\n1. Checkout\n\n2. Leave Coffeetopia\n\n")
        if Number == '1':
            NumberCorrect = NumberCorrect + 1
            if len(CustomerPurchases.cart) > 0:  #Insures there is something in the cart
                print("\nYour cart includes the following item: \n")
                num = 1
                for products in CustomerPurchases.cart:  #For loop to type out the final product name from the cart created.
                    print(str(num) + ". " + products + "\n")
                    num = num + 1
                #################################################################
                print("The final price is: $" + str(CustomerPurchases.finalpay))
                input("To complete your purchase, please press Enter!\n")
                #################################################################
                eval(beans).inventory = (eval(beans).inventory - 1) #This decreases the inventory in store
                CustomerPurchases.cart.clear()
                #################################################################
                NumberCorrect = 0
                while (NumberCorrect == 0):
                    Number = input("Would you like to:\n\n1. Continute shopping with us\n\n2. Leave Coffeetopia\n\n") #This gives the user the choice to continute shopping
                    if Number == '1':
                        NumberCorrect = NumberCorrect + 1
                        main()
                    elif Number == '2':                  
                        print("\nWe hope that you will love our wonderful coffee beans!\nSee you next time!\n") 
                        NumberCorrect = NumberCorrect + 1   
                        return 0           
        elif Number == '2':
            NumberCorrect = NumberCorrect + 1
            print("\nThank you for visiting our site!\n\nSee you next time :)") #Goodbye statement if customer is leaving instead of checking out.
            return 0

def main():

    #Firstly, we give the user the options of coffee beans that are available 
    print("\nPlease choose from the following kinds of a 500g bag of coffee beans:\n\n\n1. Arabica - Makes coffee that is sweet and aromatic. A delicate flavor with low acidity.\n")
    print("2. Robusta - Earthy, Robust, and Chocolaty. Low acidity with more bitterness.\n")
    print("3. Liberica - A rare kind of coffee that is BOLD. A strong aroma with a fruity and woody taste.\n" )   
    compute(FindChoice()) #We run our compute function
    return 0

main()

#Finally, we show the inventory of every kind of coffee bean and how it decreased.
print("\n\nThe final inventory of the each of the coffee bean bags can be found below:\n\n")
print("Arabica Beans: " + str(Arabica.inventory) + "\n\nRobusta Beans: " + str(Robusta.inventory) + "\n\nLiberica Beans: " + str(Liberica.inventory))

print("\nThank you for taking the time to test my code! I look forward to hearing from you. - Ahmed")







               

    












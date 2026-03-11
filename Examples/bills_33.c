//******************************************************************
// program name: bills.c
// 
// Cs210
// Nov 15 2010
// Program description: This program gets the amount the user wishes
// to withdraw, then gives them the least amount of bills.
//*******************************************************************


#include <stdio.h>

//Function prototypes

//This function takes in data from the user. The address of a variable
// from main is passed into this function. The function will send
// a value back to the variable in main by a pointer.

void get_data(int *amount);


//This function takes in the value of amount, and finds the number of
//fifties, twenties, and tens needed to satisfy the amount. Returns
//those values through a pointer to the adress of the variables in
//main.

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);

//Takes in the values of the variables from main, and displays them
//through a printf function

void printBills(int amount, int fifties, int twenties, int tens);


int main(void)
{

// declaring variables

    int withdraw;
    int Fifties;
    int Twenties;
    int Tens;
    char answer = 'y';

//The user can choose to run the program again after
//first use.

    while(answer == 'y' || answer == 'Y')
{    

//Passing the adress of withdraw into get data func
    get_data(&withdraw);

//Passing the value of withdraw and the adresses of
//Fifties, Twenties, Tens.
    
    dispenseBills(withdraw, &Fifties, &Twenties, &Tens);

//Passing the values of all the variables into func

    printBills(withdraw, Fifties, Twenties, Tens);

//Asking user if they would like to run the program again	    
    printf("Would you like to run the program again?\n");
    scanf(" %c", &answer);
}	
    
  return 0;
}

//Function definitions

void get_data(int *amount)
{
     //Asking user for correct input
     printf("Please enter the amount of money you would like. \n");
     printf("NOTE: Amount must be a multiple of ten.\n");
     scanf("%d", amount);
     
     
     //Checking to see if value is multiple of ten
     //If it is not user will be asked again.
     while(*amount % 10  != 0)
     {
          printf("Amount is not a multiple of ten. Try again.\n");
                 scanf("%d", amount);
                 }
     

                 }

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
//declaring local variables

     int fiftyBucks = 0;
     int twentyBucks = 0;
     int tenBucks= 0;

//Will stop the algorithm when amount is 0
     while(amount != 0)
     {

//Checking which kind of bill is needed to satisfy amount
     if(amount >= 50)
     {
               amount = amount - 50;
               fiftyBucks = fiftyBucks + 1;
               }
               else if(amount >= 20)
               {
                   amount = amount - 20;
                    twentyBucks = twentyBucks +  1;
                    }
                    else
                    {
                        amount = amount - 10;
                        tenBucks = tenBucks + 1;
                        }
                        }

//returning values to main through pointers
	*fifties = fiftyBucks;
	*twenties = twentyBucks;
	*tens = tenBucks;
                        }
void printBills(int amount, int fifties, int twenties, int tens)
{
//displaying values
     printf("You are withdrawing $%d\n", amount);
     printf("You recieve %d fifty dollar bill(s)\n", fifties);
     printf("You recieve %d twenty dollar bill(s)\n", twenties);
     printf("You recieve %d ten dollar bill(s)\n\n\n", tens);
}
           



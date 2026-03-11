//* * * * * * * * * * * * * * * * * * * * * * * * * *
//
//	program:     Assign 5
//
//	Name   :     
//	Email  :    
//
//	Description: automatic teller machine
//
//	Date:        Nov 15 2010
//
// * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <stdio.h>
#include <math.h>

void get_data(int *amount);
//Pre: Receievs data from user
//Post: Stores result in cell pointed by amount

void dispenseBills(int amount, int *fifties, int *twenties,int *tens);
//Pre: Seperates input into three parts
//Post: Results are stored in memory cell pointed to fifties, twenties, tens

void printBills(int amount, int fifties, int twenties, int tens);
//Pre: Takes all data from sorting
//Post: Prints correct order of bills and other important data

int main(void)
{	
  int fty;	//value: sorting of fifties
  int twty;	//value: sorting of twenties
  int tn;	//value: sorting of tens
  int amount;   //input: value entered by user
  char ans;     //input: Users answer from do while question at end of loop 
 

  //Do while loop: Goes through all functions then asks to make another transaction. If Yes, it will do another iteration of the loop. 
  do { 
 
	get_data(&amount);

	dispenseBills(amount, &fty, &twty, &tn);

	printBills(amount, fty, twty, tn);

	printf("Do you want to make another transaction? \n");
        scanf(" %c",&ans);

      } while (ans == 'y'|| ans == 'Y');
      
   

  return(0);
}

void get_data(int *amount)	
{        
	printf("Enter withdrawl amount --> "); //Gets amount from user(input question)
	scanf("%d", amount);
	
	while (*amount % 10) //Will output following if there is a remainder
  {
	printf("This machine ONLY dispenses $50, $20, $10 \n");
	printf("Please enter again --> ");
	scanf("%d", amount); //Gets amount from user(input question-2nd try)
  }
}

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
  // equations for sorting fities, twenties and tens
  if (amount >= 10) 
  {
    *fifties = (amount / 50);
    amount = amount - (*fifties * 50);

    *twenties = (amount / 20);
    amount = amount - (*twenties * 20);

    *tens = (amount / 10);
    amount = amount - (*tens * 10);
  }
  
}

void printBills(int amount, int fifties, int twenties, int tens)
{       // Prints out the following data. After this, it will ask to make another transaction. 
	printf("The amount you are withdrawing = $%d \n", amount);
	printf("**Take your cash as $$$ bills**\n");
	printf("%d fifties %d twenties and %d tens \n",fifties, twenties, tens);	
}           
	  

//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//	program:	Assignment 5
//
//	Name:		
//	Email:		
//
//	Description:	This program tells an automatic teller machine to 
//                      dispense money using the least amount of bills.
//
//	Date:		11-15-10
//
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>

void get_data(int *num);
/* gets the number entered by the user 
   pre - num contains an address of a memory cell where the
         results are to be stored.
   post -function stores the result in cell pointed to by num */

void dispenseBills(double num, int *fifties, int *twenties, int *tens);
/* sorts the bills into fifties, twenties, and tens
   pre - num is defined. fifties, twenties and tens
         contain an addresses of a locations 
   post - results are stored in cell pointed to by 
          fifites, twenties and tens */

void printBills(int num, int fifties, int twenties, int tens);
/* prints the results - the amount of money desired and how many of each bill
   will be dispensed*/

int main(void)
{
  int amount, fif, twen, tn;

  char ans= 'Y'; /* the users response */

  while (ans == 'Y' || ans == 'y')
  {

  get_data(&amount);

  dispenseBills(amount, &fif, &twen, &tn);

  printBills(amount, fif, twen, tn);

  printf("Do you want another transaction (y/n)?  ");
  scanf(" %c",&ans);

  } // end of loop
  
  return (0);
}

void get_data(int *num)
{
  printf("Enter how much cash do you need?  ");
  scanf("%d", num);

  while (*num % 10)
  {
    printf("This machine dispenses ONLY $50, $20, $10... \n");
    printf("Please enter again ");
    scanf("%d", num);
  }
}

void dispenseBills(double num, int *fifties, int *twenties, int *tens)
{
  if (num >= 10)
  {
    *fifties = num / 50;
    num = num - (*fifties * 50);
    *twenties = num / 20;
    num = num - (*twenties * 20);
    *tens = num / 10;
    num = num - (*tens * 10);
  }
}

void printBills(int num, int fifties, int twenties, int tens)
{
  printf("The amount you are withdrawing = $ %d\n", num);
  printf("*** Take your cash as $$$ bills ***\n");
  printf("%d fifties %d twenties and %d tens\n\n", fifties, twenties, tens);
}

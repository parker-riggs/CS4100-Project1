/****************************************************************
* Name: 
* Date: 11/06/10
* Class: CS 210
* Section: A02
*
* Description: This program takes an input amount and then
* breaks it up into the dollor bill amounts of 50, 20, and 10's.
* 
*****************************************************************/

#include <stdio.h>
#include <math.h>

void get_data(int *num);
void dispenseBills(int num, int *fif, int *tew, int *ten);
void printBills(int num, int fif, int tew, int ten);

int main(void)
{
 int amount;    /* Input - The amount the user wants to withdraw */
 int fifties;   /* Output - How many fifites are in amount       */
 int twenties;  /* Output - How many twenties are in amount      */
 int tens;      /* Output - How many tens are in amount          */

 char ans ='Y'; /* The Users Response */
	
	/* A while loop that checks if the user wants to continue
	   making transactions.                                  */
	while (ans == 'Y' || ans == 'y')
	{
		/* Calls the function get_data to get amount to withdraw */
		get_data(&amount);
		/* Calls the function dispenseBills to Seperate amount into
		   fifties, twenties, and tens.                 */
		dispenseBills(amount, &fifties, &twenties, &tens);
		/* Calls the functin printBills to print the bills needed
		   to make the amount.                          */
		printBills(amount, fifties, twenties, tens);
		
		/* Ask and store if the user wants to do another transaction*/
		printf("Do you want another transaction (y/n)? ");
		scanf(" %c", &ans);
	}

   return 0;
}

void get_data(int *num)
{
	/* Prompt and store how much cash the user needs */
	printf("Enter how much cash you need? $");
	scanf("%d", num);
	
	/* A loop that runs while the remainder of *num is greater
	   than 0.                                                */
	while (*num % 10 >  0)
	{
	/*Explain to the user that the machine only outputs
	  $50, $20, $10... then prompt them again.         */
	printf("This machine dispenses ONLY $50, $20, $10...\n");
	printf("Please enter again $");
	scanf("%d", num);
	}
	/* Tell the user how much money they are withdrawing */
	printf("The amount you are withdrawing = $%d\n", *num);
}

void dispenseBills(int num, int *fif, int *tew, int *ten)
{
	/* Calculates how many fifties are needed. */
	*fif = num / 50;
	/* Calculates how many twenties are needed. */
	*tew = (num - (*fif * 50))/20;
	/*Calculates how many tens are needed. */
	*ten = (num - (*fif * 50) - (*tew * 20)) / 10;
}

void printBills(int num, int fif, int tew, int ten)
{
	/* Tells the user how they will be recieving their money */
	printf("*** Take your Cash as $$$ bills ***\n");
	printf("%d fifty %d twenties and %d tens\n", fif, tew, ten);
}

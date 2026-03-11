/*************************************************************************************************************************************
* Program: Bills.c
* Name: 
* Email: 
* Date: November 8, 2010
* Description: This program dispenses the amount of money entered by the user using the least number of bills,
*		which are 50s, 20s, and 10s.
**************************************************************************************************************************************/

#include <stdio.h>

void get_data(int *amount);

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);

void printBills(int amount, int fifties, int twenties, int tens);

int main (void)
{
	int amount, /* input - desired amount entered */
	fifties,  /* output - number of 50 dollar bills */
	twenties, /* output - number of 20 dollar bills  */
	tens; /* output - number of 10 dollar bills */
	char again; /* input - lets user perform another transaction */
	
	
	do {
	get_data(&amount);
	
	dispenseBills(amount, &fifties, &twenties, &tens);

	printBills(amount, fifties, twenties, tens);
	
	printf("Do you want another transaction (y/n)?\n");
        scanf(" %c",&again);

	} while (again == 'Y' || again == 'y');	 // end of loop

	return (0);
} // end of main

/* pre - prompts user on the amount being withdrawn
   post - if incorrect, gives user another chance to reenter the amount */

void get_data(int *amt)
{

	printf ("Enter the desired amount you need: \n");
        scanf ("%d",amt);

	while ((*amt % 10) != 0)
	{
        	printf("The machine dispenses ONLY $50, $20, $10...\n Please enter amount again:\n");
		scanf("%d",amt);
	} // end of loop
}

/* pre - Divides amount into number of 50's, 20's, and 10's bills
   post - number of bills returned to user */

void dispenseBills(int amt, int *F, int *TW, int *T)
{

	/* Finds least number of specific bills */
	
	int remainder; /* amount of cash leftover */

	if (amt >= 50)
	{
		*F = amt / 50;
		remainder = amt % 50;
			if (remainder >= 20)
			{*TW = (amt % 50) / 20; 
			remainder = (amt % 50) % 20;
			}
			else if (remainder ==0)
			*TW = 0;	
				if (remainder >= 10)
				*T = ((amt % 50) % 20) / 10;
				else if (remainder ==0)
				*T = 0;
	}

	else if (amt >= 20)
	{	*TW = amt / 20;
		remainder = amt % 20;
			if (remainder >= 10)
			*T = (amt % 20) / 10;
			else
			*T = 0;
	}

		else
	{	*T = amt / 10;
		
	}
	
	
}


/* pre - contains the numbers and amount of bills
   post - prints the amount and number of bills */

void printBills(int amt, int F, int TW, int T)
{
	printf ("The amount you are withdrawing: %d\n",amt);
	printf("Take your Cash as $$$ bills\n %d fifty %d twenties and %d tens\n",F,TW,T);
	
}

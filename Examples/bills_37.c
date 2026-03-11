// * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//	Program: Bills.c
//
//	Name: 
//	Email:
//	
//	Date: 11-12-10
//
// * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>
#include <math.h>

void get_data(int *amount); // Function prototype which gets the amount of money from the user. Also flags user if amount is invalid.

void dispense_bills(int amount, int *fifties, int *twenties, int *tens); // Function prototype which divides the amount of money into 50's 20's and 10's.

void print_bills(int amount, int fifties, int twenties, int tens); // Function prototype which prints the amount of bills received.

int main(void) // Main Function

{ 
   int amount;
   int fift;
   int twent;
   int ten;
   char ans;
	
do { // Do while loop that runs through each function.

	get_data(&amount);

	dispense_bills(amount,&fift,&twent,&ten);

	print_bills(amount, fift, twent, ten);

        printf ("Would you like to make another transaction? \n");
	scanf (" %c", &ans);

    }	while (ans == 'Y' || ans == 'y');

return (0);	
}

void get_data(int *amount)
{

printf ("Enter the amount you would  like to withdrawl: " );
scanf ("%d", amount);

while (*amount % 10)
	{
		
		printf ("This machine dispenses only $50, $20, and 10$...\n");
		
		printf ("Please enter another amount.");
		scanf ("%d", amount);
		
	}	
}

void dispense_bills (int amount, int *fifties, int *twenties, int *tens)

{

	if (amount >= 10);
		{
                *fifties = (amount / 50);
		amount = amount - (*fifties * 50);

		*twenties  = (amount / 20);
                amount = amount - (*twenties * 20);

		*tens = (amount / 10); 
                amount = amount - (*tens * 10); 

		}
	
}
			
			
void print_bills(amount, fifties, twenties, tens) // Divides the amount into the least amount of bills.
{
printf ("The amount you are withdrawing = $%d \n", amount);
printf ("*** Take your cash as $$$ bills *** \n");
printf ("%d fifty %d twenties and %d tens \n", fifties, twenties, tens);
}

























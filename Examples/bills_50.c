/* 	
	Name 		
	Program		bills.c
	Purpose		calculates how many of each bill to dispense
	Class		cs 210
	Date		11-15- 2010
*/

#include <stdio.h>

void get_data(int *amount); // Gets amount needed from the user
void dispense_bills(int amo, int *fifties, int *twenties, int *tens); // calculates how many 10 20 and 50 bills are needed
void print_bills(int amount, int fifties, int twenties, int tens); // Prints the output to the screen

int main(void)
{	
	// Declare local variables
	char prompt = 'y'; // Initialize the loop variable
	int amo, fif, twe, ten;
	
	
	while (prompt == 'Y' || prompt == 'y') {   // Loop runs until user doesn't enter y
		
		get_data(&amo);

		dispense_bills(amo, &fif, &twe, &ten);

		print_bills(amo, fif, twe, ten);

		printf("\n\nDo you want to enter another amount (y)/(n)  >>  ");
		scanf(" %c", &prompt);
	} 
		
	
	return(0);

}

void get_data(int *amount)
{
	 
	
	while (*amount % 10 != 0)  // checks to make sure the amount is a multiple of ten
	{
		printf("Enter amount in multiples of ten >> ");
		scanf("%d", amount);
		
	}
	
}

void dispense_bills(int amount, int *fifties, int *twenties, int *tens)
{
	
	
	// counts how many of each bill type is needed
	
	for(*fifties = 0; amount >= 50; ++ *fifties) 
		amount = amount - 50;
	
	for(*twenties = 0; amount >= 20; ++ *twenties)
		amount = amount - 20;

	for(*tens = 0; amount >= 10; ++ *tens)
		amount = amount - 10;
	
}

void print_bills(int amount, int fifties, int twenties, int tens)
{
	printf("\n\nYou entered %d, you get %d, fifties %d, twenties %d, tens", amount, fifties, twenties, tens);

}

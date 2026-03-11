// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// bills.c
// 
// 
// 11/7/10
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#include <stdio.h>
#include <math.h>


void
get_data(int *total);
/* Gets data entered by user
   pre - total contains an adress of a memory cell where the amount of money are to be stored.
   post - function stores amount in a cell pointed to by total	*/

void
dispense_bills(int total, int *big, int *medium, int *small);
/* Divide the amount into number of 50's, 20's, and 10's bills
   pre - Amount is entered into the function
   post - function divides amount into number of fifties, twenties, and tens  */

void
print_bills(int total, int big, int medium, int small);
/* Prints the amount of 50's, 20's and 10's to be dispensed */

int
main(void)
{

	int amount;	/* input - amount entered by user */
	int fifties;	/* Number of fifty dollar bills to be dispensed from input value */
	int twenties;	/* Number of twenty dollar bills to be dispensed from input value*/
	int tens;	/* Number of ten dollar bills to be dispensed from input value */

	char status = 'Y';

	while (status == 'y' || status == 'Y') 
	{
		get_data(&amount);	// Call to the function get_data

		dispense_bills(amount, &fifties, &twenties, &tens);	// Call to the function dispense_bills

		print_bills(amount, fifties, twenties, tens);		// Call to the function print_bills
	
		printf("Do you want another transaction (y/n)?  ");
		scanf(" %c", &status);
	}

	return (0);
}

void get_data(int *total)
{
	int correct;

	printf("Enter how much cash you need : ");
	scanf("%d", total);

	correct = *total % 10;

	if ( correct == 0);

	else
	{
		printf("This machine only dispenes $50, $20, $10... \n");
		printf("Please enter amount again : \n");
		scanf("%d", total);
	}
}

void dispense_bills(int total, int *big, int *medium, int *small)
{
	
	*big = total / 50;

	total = total - (*big) * 50;

	*medium = total / 20;

	total = total - (*medium) * 20;

	*small = total / 10;
}

void print_bills(int total, int big, int medium, int small)
{
	printf("The amount you are withdrawing = $ %d\n", total);
	printf("*** Take your cash as $$$ bills ***\n");
	printf("%d fifty %d twenties %d tens\n", big, medium, small);
}

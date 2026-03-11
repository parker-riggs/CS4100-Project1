// ******************************************************************
// *                                                                *
// * 
// * 
// * A01                                                            *
// * 11-15-10                                                       *
// *                                                                *
// * This program will serve as an automatic teller machine that    *
// * dispences money. The user will input the desired amount in     *
// * multiples of 10. The program will then despense the least      *
// * number of bills, using 50s, 20s, and 10s.                      *
// *                                                                *
// ******************************************************************

#include <stdio.h>

void get_data(int *value);
/* Gets the amount entered by the user
   Pre: value contains the address of a memory cell where the amount
        is to be stored
  Post: function stores the amount in the cell pointed to by value
*/

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);
/* Seperates the amount into least amount of bills
   Pre: amount is defined. fifties, twenties, and tens contains the 
        address of a memory cell where the amount is to be stored
  Post: results are stored in a cell pointed to by fifties, twenties,
	and tens
*/

void printBills(int amount, int fifties, int twenties, int tens);
/* Prints the results - the amount, and the number of fifties,
   twenties, and tens
*/

int main(void)
{
	int amount;   /* input - amount of money       */
	int fifties;  /* number of fifty dollar bills  */
	int twenties; /* number of twenty dollar bills */
	int tens;     /* number of ten dollar bills    */

	char ans = 'Y'; /* the user's response */

	while(ans == 'Y' || ans == 'y')
	{
	get_data(&amount);

	dispenseBills(amount, &fifties, &twenties, &tens);

	printBills(amount, fifties, twenties, tens);
	
	printf("\nDo you want another transaction? Y/N ");
	scanf(" %c", &ans);
	}

	return (0);
}


void get_data(int *value)
{
        printf("Enter how much cash you need in multiples of 10 > $");
        scanf("%d", value);

	while(*value%10 != 0 || *value <= 0)
	   {
	    printf("%d is not a multiple of 10. ", *value);
	    printf("This machine dispences ONLY $50, $20, and $10.\n");
	    printf("Enter how much cash you need in multiples ");
	    printf("of 10 > $");
	    scanf("%d", value);
	   }
}


void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{	
	*fifties = amount / 50;
	*twenties = (amount - (*fifties * 50)) / 20;
	*tens = (amount - (*fifties * 50) - (*twenties * 20)) / 10;
}


void printBills(int amount, int fifties, int twenties, int tens)
{
        printf("\nThe amount you are withdraweling is $%d", amount);
        printf("\n\t*** Take your Cash as $$$ bills ***\n");
	printf("%d fifties, %d twenties, ", fifties, twenties);
	printf("%d tens\n", tens);
}

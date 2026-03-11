//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//      Program: bills.c
//
//      Name: 
//      Email:
//
//      Description: 
//
//	
//
//      Date: 11/11/2010
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include <stdio.h>

void get_data(int *num);
/*	pre- num contains address of memory cell where value of amount 
	     being withdrawn is stored.
	post- function stores value in cell pointed to by num
*/

void dispenseBills(int num, int *fifties, int *twenties, int *tens);
/*	pre- fifties,twenties, and tens contain addresses of memory 
	     cells where amount of bills is stored.
	post- amount of bills stored in cells pointed to by fifties, 
	      twenties and tens.
*/

void printBills(int num, int fifties, int twenties, int tens);
/*	pre- The values stored in cells for fifties, twenties, and tens. 
	     Along with the original value entered to be withdrawn.
	post- Prints the amount of fifty, twenty, and ten dollar bills.
*/

int main (void)
{
	int amount;	/*input- amt entered by usuer */
	int	 x,	
	         y,
	         z;

	char ans= 'Y';	/* users response */

	while ( ans == 'Y' || ans == 'y' ){

		get_data(&amount);

		dispenseBills(amount, &x, &y, &z);

		printBills(amount, x, y, z);
	
		printf("Do you want another transaction y/n ? \n");
		scanf(" %c", &ans);
	}

	return 0;

}

void get_data(int *num)
{
	int  val;	/* local variable, input entered by user */
	int term;	

	printf("How much money would you like? $ ");
	scanf("%d", &val);
	
	term = val % 10;

	/* start loop if amount entered is not multiple of 10 */

 	while (term != 0)
	{
	printf("This machine dispenses ONLY $50,$20,$10...\n");
	printf("Please enter again. $ ");
	scanf("%lf", &val);
	}

	*num = val;
}

void dispenseBills(int num, int *fifties, int *twenties, int *tens)
{

	*fifties = num / 50;
	*twenties = (num %= 50) / 20;
	*tens = (num  %= 20) / 10;
}

void printBills (int num, int fifties, int twenties, int tens)
{
	printf("\nThe amount you are withdrawing- $%d\n",num);
	printf("*** Take your Cash as $$$ Bills ***\n");
	printf("%d Fifty %d Twenties %d Tens\n\n",fifties,twenties,tens);	
}

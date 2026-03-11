// * * * * * * * * * *
// bills.c
// 
// 
// 11/15/2010
// Description: This program is for a 
// money dispensing machine that dispenses 
// the amount (multiple of 10 dollars) in 
// the least number of bills. (10s, 20s, 50s)
// * * * * * * * * * *

#include <stdio.h>

void get_data (int *request);
/*pre- Enter the desired amount
post- Determinds whether or not it is possible to be dispensed
*/
void dispenseBills (int amount, int *large, int *medium, int *small);
/*pre- Takes the desired amount and splits it into bills
post - determinds how many of each bill it takes to make the desired amount
*/
void printBills (int amount, int fifties, int twenties, int tens);
/* pre- Gives you your requested amount
post- tells you how many of each bill
*/


int main(void)
{

	int fifties;  		// the number of 50's in your amount
	int twenties;		// the number of 20's in your amount
	int tens;		// the number of 10's in your amount
	int amount;		// the amount requested
	char answer= 'Y';	// character answering if you want another transaction

	
	while (answer == 'Y' || answer == 'y')
	{
		/*Enter the desired amount.  if the amount is incorrect 
		(not a multiple of 10) give the user a chance to reenter 
		the amount*/
		get_data(&amount);
		
		/*divide the amount into number of 50's 20's 10's bills */
		dispenseBills(amount, &fifties, &twenties, &tens);
		
		/*print the amount and the number of 50's 20's 10's bills */
		printBills(amount, fifties, twenties, tens);

		printf("Would you like to make another transaction (Y/N)? ");
		scanf(" %c", &answer);
	}
return (0);
}


void get_data(int *request)
{
	int value;
	
	printf("Enter how much cash you need > $ ");
	scanf("%d", &value);
	
	while (value %10 !=0)
	{
		printf("This Machine dispenses ONLY $50, $20, $10... \n");
		printf("Please enter again $");
		scanf("%d", &value);
	}
	
	*request = value;
}


void dispenseBills (int amount, int *large, int *medium, int *small)
{
	int remain;
	int left;
	
	*large = amount / 50;
	left = amount %50;

	*medium = left / 20;
	remain = left %20;
	
	*small = remain / 10;
}


void printBills(int amount, int fifties, int twenties, int tens)
{
	printf("The Amount your Withdrawing = $%d\n", amount);
	printf("*** Take Your Cash ***\n");
	printf("%d Fifties, %d Twenties, %d Tens \n\n", fifties, twenties, tens);
}

































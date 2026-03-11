//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//
//
// Description: Takes an input from a user and dispenses the amount of 
//  money using the least number of bills
//
// Date: 11/14/2010
//
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#include <stdio.h>

void get_data(int *num);
	/*Pre - num contains an address of a memory cell where the results are stored
	Post - The function stores the result in the cell that is pointed to by num
	*/
 
void dispenseBills (int total, int *fifty, int *twenty, int *ten);
	/*Pre - total is defined where fifty, twenty and ten and address locations
	Post - Results are stored in the locations that are pointed to by fifty, twenty and ten
	*/
	
void print(int tot, int fifty, int twenty, int ten);
	/* Prints the resulte - the amount, number of fifties, twenties, and tens
	*/
int main(void)
{

	int amount,
	    fifties,
	    twenties,
	    tens;

	char ans = 'Y';


	while ( ans == 'Y' || ans =='y')
	{
		get_data(&amount);

		dispenseBills(amount, &fifties, &twenties, &tens);

		print(amount, fifties, twenties, tens);

		printf("Do you want another transaction? (y/n): ");
		scanf(" %c", &ans);
	}
		

	return (0);
}

void get_data(int *num)
{
	int val;
	
	printf("Enter how much cash you need: ");
	scanf("%d", &val);

	while (val%10 != 0)
	{
		printf("This machine dispenses ONLY $50, $20, $10..\n");
		printf("Please enter again: ");
		scanf("%d", &val);
	}

	*num = val;
}

void dispenseBills (int num, int *fifty, int *twenty, int *ten)
{
	int five,
	    two,
	    one;
	
	five = num / 50;
	num = num - (five * 50);
	two = num / 20;
	num = num - (two *20);
	one = num / 10;
	
	*fifty = five;
	*twenty = two;
	*ten = one;
}

void print(int num, int fifty, int twenty, int ten)
{
	printf("The amount you are withdrawing = %d\n", num);
	printf("*** Take your Cash as $$$ Bills ***\n");
	printf("%d fifties, %d twenties and %d tens\n", fifty, twenty, ten);
}

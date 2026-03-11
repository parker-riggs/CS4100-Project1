	/***************************************************
	 * Program: bills.c
	 * Name: 
	 * Email:
	 * Date: November 15, 2010
	 * Class: CS210 A04
	 * This program reads a dollar amount and gives the
	 * amount using the fewest number of bills. 
	 * The bills are dispensed in 10s, 20s, and 50s.
	 ***************************************************/

#include <stdio.h>

void get_data(int *amt);
/* gets the amount entered by the user 
 * Pre - amt contains an address of a memory cell where the
 *       results are to be stored.
 * Post -function stores the amount in the cell pointed to by amt */

void dispenseBills(int amt, int *num_fifty, int *num_twenty, int *num_ten);
/* divides the amount into bills
 * Pre - amt is defined. num_fifty, num_twenty, num_ten
 *       contain the addresses of a locations 
 * Post - the number of bills are stored in cell pointed to by 
 *        num_fifty, num_twenty, and num_ten */

void printBills(int amt, int num_fifty, int num_twenty, int num_ten);
/* prints the amount and number of bills
 * Pre - amt, num_fifty, num_twenty, and num_ten have values.
 * Post - prints the results */

int main(void)
{
	int amount;		/* desired amount of cash */
	int fifties;		/* number of fifty dollar bills */
	int twenties;		/* number of twenty dollar bills */
	int tens;		/* number of ten dollar bills */
	char ans = 'Y';		/* input - Y/N to make another transaction */

   while (ans == 'Y' || ans == 'y')
	{
	   // User enters the desired amount. Must be a multiple of ten.
	   get_data(&amount);

	   // Divide the amount into number of 50s 20s and 10s bills
	   dispenseBills(amount, &fifties, &twenties, &tens);

	   // Print the amount and the number of 50s 20s and 10s bills
	   printBills(amount, fifties, twenties, tens);

	   printf("Do you want to make another transaction (Y/N)? ");
	   scanf(" %c", &ans);
	}

   return (0);
}

void get_data(int *amt)
{
   printf("\nEnter how much cash you need: $");
   scanf("%d", amt);

   while (*amt % 10 != 0)
	{
	   printf("This machine dispenses ONLY $50, $20, $10.\n");
	   printf("Please enter another amount: $");
	   scanf("%d", amt);
	}
}

void dispenseBills(int amt, int *num_fifty, int *num_twenty, int *num_ten)
{
   int remainder;

   *num_fifty = amt/50;
   remainder = amt % 50;

   *num_twenty = remainder/20;
   remainder = remainder % 20;

   *num_ten = remainder/10;
}

void printBills(int amt, int num_fifty, int num_twenty, int num_ten)
{
   printf("The amount you are withdrawing is $%d\n", amt);
   printf("*** Take your cash as $$$ bills ***\n");
   printf("%d fifties, %d twenties, %d tens\n\n", num_fifty, num_twenty, num_ten);
}

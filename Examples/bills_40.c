//*********************************************************************
// Program: bills.c
// Name: 
// Email:
// Description: This program asks the user how much money the want and
//		tells them how many 50's, 20's and 10's they should
//		get.
// Date: November 15, 2010
//**********************************************************************

#include <stdio.h>

void get_data(int *amount);
/* pre: takes in amount of money entered by user
   post: determines if amount is a multiple of 10
*/

void dispense_bills(int amount, int *fifties, int *twenties, int *tens);
/* pre: takes in amount of money
   post: outputs number of 50's, 20's, and 10's
*/

void print_bills(int amount, int fifties, int twenties, int tens);
/* pre: takes in amount and number of 50's, 20's and 10's
   post: outputs information
*/

int main(void)
{
	int withdraw_amount;
	int num_fifties;
	int num_twenties;
	int num_tens;
	char repeat;

	do
	{
	 get_data(&withdraw_amount);

	 dispense_bills(withdraw_amount, &num_fifties, &num_twenties, &num_tens);

	 print_bills(withdraw_amount, num_fifties, num_twenties, num_tens);
	
	 printf("Do you wish to perform another transaction (y/n)? ");
	 scanf(" %c", &repeat);
	}while(repeat=='y'||repeat=='Y');

	printf("\n");
	return(0);
}

void get_data(int *amount)
{
	double remainder;
	int input_status;
	char bad_char;

	printf("\nEnter amount to withdraw: $ ");
	input_status = scanf("%d", amount);  

	while(input_status != 1)
	{
	 scanf("%c", &bad_char);
         printf("Invalid character input %c.\n", bad_char);
	 printf("Please enter amount again: $ ");
	 input_status = scanf("%d", amount);
	}

	remainder = *amount % 10; 

	while(remainder != 0)
	{
	 printf("This machine dispenses ONLY $50, $20, $10...\n");
	 printf("Please enter amount again: $ ");
	 scanf("%d", amount);
	 remainder = *amount %10;
	}

}

void dispense_bills(int amount, int *fifties, int *twenties, int *tens)
{
	int new;

	*fifties = amount / 50;
	new = amount % 50;

	*twenties = new / 20;
	new = new % 20;

	*tens = new / 10;	

}

void print_bills(int amount, int fifties, int twenties, int tens)
{
	printf("The amount you are withdrawing = $%d\n", amount);
	printf("*** Take your cash as $$$ bills ***\n");
	printf("%d fifties, %d twenties, %d tens\n", fifties, twenties, tens);
}

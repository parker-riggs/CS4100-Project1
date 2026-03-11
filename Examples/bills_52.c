//Name: 
//Email:
//Date: November 6th 2010
//Lab Section: Thursday @6pm
//Program: Assignment 5
//Description: This program takes inputted information from a user and 
//acts as an ATM and makes withdrawls for the user.

#include <stdio.h>

void get_data(int *amount);
// gets the number to withdraw from user
// pre - amount contains the address of a memory cell where
// the results are to be stored.
// post - function stores the result in the cell pointed to by amount


void dispenseBills(int amount, int *fifties, int *twenties, int *tens);
// seperates amount into three amounts
// pre - amount is defined. fifties, twenties, and tens contain
// address locations
// post - results are stored in cells pointed to by fifties, twenties, and tens


void printBills(int amount, int fifties, int twenties, int tens);
// prints the results - the original amount, fifties, twenties, and tens

int main(void)
{
	char ch; // loop sentinel
	int input; // value inputted by user
	int fif, twen, ten; // variables for fifties, twenties, and tens
	do
	{
		get_data(&input);
		dispenseBills(input, &fif, &twen, &ten);
		printBills(input, fif, twen, ten);
		printf("\n");
		printf("Do you want another transation (y/n)? ");
		scanf(" %c", &ch);
		printf("\n");
		if(ch != 'n' || ch != 'N' || ch != 'y' || ch != 'Y')
		{
			printf("Invalid Input. Transaction Terminated.\n");
		}
		else{}
		
	}while(ch == 'y' || ch == 'Y');
	return(0);
}

void get_data(int *amount)
{
	int temp; // temporary assignment integer
	printf("Enter the amount of cash to withdraw: ");
	scanf("%d", amount);
	if(*amount%10 != 0)
	{
		do
		{
		printf("This machine dispenses ONLY $50, $20, $10...\n");
		printf("Please enter again: ");
		scanf("%d", &temp);
		*amount = temp;
		}while(*amount%10 != 0);
	}
	else
	{
	}
}

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
	*fifties = amount / 50;
	*twenties = (amount - (*fifties*50)) / 20;
	*tens = (amount - (*fifties*50) - (*twenties*20)) / 10;
}

void printBills(int amount, int fifties, int twenties, int tens)
{
	printf("The amount you are withdrawing = $%d\n", amount);
	printf("*** Take Your Cash as $$$ bills ***\n");
	printf("%d fifty(ies) %d twenty(ies) and %d ten(s)\n", fifties, twenties, tens);
}
	

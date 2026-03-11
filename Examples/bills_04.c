//* * * * * * * * * * * * * * * * * * * * *
//
//   Program: bills.c
//
//   Name   : 
//   Email  :
//
//   Description: Program for automatic teller machine that dispenses money. 
//
//   Date   : 11/14/10
//
//* * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>


void get_data(int *amount);

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);

void printBills(int amount, int fifties, int twenties, int tens);


int main(void)
{
	int amount;
	int fifties;
	int twenties;
	int tens;


	char ans= 'Y'; 
	while (ans == 'Y' || ans == 'y')
	{

		get_data(&amount);

		dispenseBills(amount, &fifties, &twenties, &tens);

		printBills(amount, fifties, twenties, tens);

		printf("Would you like another transaction? y/n ");
		scanf(" %c", &ans);
	}

	return (0);
}



void get_data(int *amount)
{
	printf("How much cash would you like to withdraw? ");
        scanf("%d", amount);

	
	while ((int)amount % 10 != 0)
		{
		printf("This machine only dispenses bills in increments of $10\n");
		printf("Please enter a new amount ");
		scanf("%d", amount);
		}
}



void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
	fifties = 0;
	while (amount >= 50)
	{
	fifties++;
	amount -= 50;
	}

	twenties = 0;
	while (amount >= 20)
	{
	twenties++;
	amount -= 20;
	}

	tens = 0;
	while (amount >= 10)
	{
	tens++;
	amount -= 10;
	}	
}




void printBills(int amount, int fifties, int twenties, int tens)
{
	printf("The amount you are withdrawing = %d\n", amount);
	printf("***Take your cash as $$$ bills.***\n");
	printf("%d Fifties, %d Twenties, and %d Tens.\n", fifties, twenties, tens);
}

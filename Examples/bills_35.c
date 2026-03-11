//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//										*
//	Name: 
//	Date: Novmeber 12, 2010							*
//										*
//	Assignment: Assignment 5						*
//										*
//	Description: A program for an ATM machine to run and dispense bills.	*
//										*
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include<stdio.h>

void get_data(int *amount);
/* This function take in no input and gives out the amount in dollars and checks to make sure its divisible by 10 */

void dispenseBills (int amount, int *fifties, int *twenties, int *tens);
/* This function inputs amount and gives back how many fifties twenties and tens to give out. */

void printBills (int amount, int fifties, int twenties, int tens);
/* This function imputs amount fifties twenties and tens and outputs no informtion or variables */

char SENTINEL = 'n';

int main(void)
{
	int amount, fifties, twenties, tens, exit; /* declares amount, fifties, tens, exit */

	char nextTrans; /* assigns nextTrans for contorlling the loop */

	/* for loop calling the three funtions in order */
	for (nextTrans = 'y'; nextTrans != SENTINEL; scanf(" %c", &nextTrans)) {
		get_data(&amount);
		dispenseBills(amount, &fifties, &twenties, &tens);
		printBills(amount, fifties, twenties, tens);
		printf("Would you like to make another transaction? y/n >");
	}
	
	/* ending message */
	printf("End Transaction. Thank You.\n");

	return(0); 

}

void get_data (int *amount)
{
	int test;	/* local variable */

	/* asking the user for amount they wish to withdraw */
	printf("Please enter the amount you wish to withdraw $");
	scanf("%d", amount);
	
	/* testing if the amount is valid */
	test = *amount % 10;
	
	/* checking if the test number is vaid and if not asking the user to try again */ 
	while (test != 0) {
		printf("This machine dispenses ONLY $50, $20, $10...\n");
		printf("Please enter another amount $");
		scanf("%d", amount);
		test = *amount % 10;	
	}
}

void dispenseBills (int amount, int *fifties, int *twenties, int *tens)
{
	int amountChange; /* local variable for change in amount */

	/* if statement deciding which case to run */
	if (amount >= 50) {
		*fifties = (amount / 50);
		amountChange = amount - (*fifties * 50);
		*twenties = (amountChange / 20);
		amountChange -= (*twenties * 20);
		*tens = (amountChange / 10);
	} else if (amount < 50 || amount > 10) {
		*fifties = 0;
		*twenties = amount / 20;
		amountChange = amount - (*twenties * 20);
		*tens = amountChange / 10;	
	} else if (amount == 10) {
		*fifties = 0;
		*twenties = 0;
		*tens = 1;
	}
}

void printBills (int amount, int fifties, int twenties, int tens)
{
	/* giving the user back the amount they are withdrawing, and how many fifties twenties and tens they are to recieve */
	printf("The amount you are withdrawing is $%d\n", amount);
	printf("**** Please take your Cash as $$$ bills ****\n");
	printf("%d fifties, %d twenties, %d tens\n", fifties, twenties, tens);
}

//	Assignment 5: bills.c
//
//	
//
//
//	This program takes an amount(multiple of ten) and separates it into fifties, 
//	twenties, and tens using the least number of bills possible.
//
//	11/15/2010  

#include <stdio.h>
#include <math.h>

void get_data (int *amount);
	/* gets amount entered by user */

void dispenseBills (int amount, int *fifties, int *twenties, int *tens);
	/* separates the amount into fifties, twenties, and tens using the 
	least number of bills */

void printBills (int amount, int fifties, int twenties, int tens);
	/* prints the results - the oringinal amount and the number of 
fifties, twenties, and tens */

int main (void){
	int amount;
	int fifties;
	int twenties;
	int tens;

	char ans = 'Y';
	while(ans == 'Y' || ans == 'y'){

		get_data (&amount);
		dispenseBills (amount, &fifties, &twenties, &tens);
		printBills (amount, fifties, twenties, tens);

		printf("Do you want another transaction (y/n)? \n");
		scanf(" %c", &ans);	
	}
	return (0);
}

void get_data (int *amount){
	printf("Enter how much cash you need \n");
	scanf("%d", amount);
	
	while( (*amount%10) != 0){
	
		printf("The amount must be a multiple of ten \n");
		scanf("%d", amount);
	}
}
		
void dispenseBills (int amount, int *fifties, int *twenties, int *tens){
	*fifties = amount / 50;
	*twenties = (amount%50) / 20;
	*tens = ((amount%50)%20) / 10;
}

void printBills (int amount, int fifties, int twenties, int tens){
	printf("The amount you are withdrawing = $%d \n", amount);
	printf("fifties: %d \n", fifties);
	printf("twenties: %d \n", twenties);
	printf("tens: %d \n", tens);
} 

//****************
//Name: 
//Program: bills.c
//Date: November 14, 2010
//Email: 
//****************

#include<stdio.h>
void get_data(int *num);
void dispensebills(int amount, int *fifties, int *twenties, int *tens);
void printbills(int amount, int fifties, int twenties, int tens);
int main(void)
{
	int amount, fifties, twenties, tens;
	char ans = 'y';

	while (ans == 'Y' || ans == 'y')
	{
		get_data(&amount);
		dispensebills(amount, &fifties, &twenties, &tens);
		printbills(amount, fifties, twenties, tens);
		printf("Would you like another transaction(y/n)?");
		scanf(" %c", &ans);
	}

	return(0);
}

void get_data(int *num){
	printf("\nEnter the amount of cash you wish to withdraw,"); 
	printf("\namount must be a multiple of 10>> $");
	scanf("%d", num);
	while (*num%10 != 0 || *num < 0){
		printf("ATM can only dispense positive multiples of 10, please re-enter value>> "); 
		scanf("%d", num); }
	}

void dispensebills(int amount, int *fifties, int *twenties, int *tens){
	
	*fifties = amount/50;	
	*twenties = (amount%50)/20;
	*tens = ((amount%50)%20)/10;
}

void printbills(int amount, int fifties, int twenties, int tens){
	printf("Amount you are withdrawing>> $%d\n", amount);
	printf("Number of fifty dollar bills> %d\n", fifties);
        printf("Number of twenty dollar bills> %d\n", twenties);
       	printf("Number of ten dollars bills> %d\n\n", tens);  
	}

//******
//	
//	CS 210 AO1
//	Assignment 5
//	11-15-10
//******

/*
 * This program dispenses bills out of an automatic teller machine
 */

#include <stdio.h>

int get_data(int *money);

int dispensebills(int money, int *fifties, int *twenties, int *tens);

int printbills(int money, int fifties, int twenties, int tens);

int main(void)
{
	int amount; /* input - amount entered by user */
	int fift; /* amount of fifties */
	int twent; /* amount of twenties */
	int ten; /* amount of tens */
	char ans= 'Y'; /* the users response */

	while (ans == 'Y' || ans == 'y'){
  
	get_data(&amount);
 
	dispensebills(amount, &fift, &twent, &ten); 
 
	printbills(amount, fift, twent, ten);
  
	printf(" Another transaction Y/N  ");
	scanf(" %c",&ans);
  }
	return (0);
}

int get_data(int *money)
{
	printf(" Enter cash amount you wish to recieve as a multiple of $10. ex $50\n");
	scanf("%d", money);

	while (*money % 10 != 0)
	{
		printf(" Enter a multiple of ten ");
		scanf("%d", money);
	}
}

int dispensebills(int money, int *fifties, int *twenties, int *tens)
{
	int money_20;
	int money_10;

	if (money % 50 == 0){
		*fifties = money / 50;
		*twenties = 0;
		*tens = 0;
	}else if (money % 20 == 0){
		*fifties = money / 50;
		money_20 = money % 50;
		*twenties = money_20 / 20;
		money_10 = money_20 % 20;
		*tens = money_10 / 10;
	}else if (money % 10 == 0){
		*fifties = money / 50;
		money_20 = money % 50;
		*twenties = money_20 / 20;
		money_10 = money_20 % 20;
		*tens = money_10 / 10;
	}
	 return (0);
		
}

int printbills(int money, int fifties, int twenties, int tens)
{
	printf(" Collect %d in cash \n", money);
	printf("%d fifties\n", fifties);
	printf("%d twenties\n", twenties);
	printf("%d tens\n", tens);
}

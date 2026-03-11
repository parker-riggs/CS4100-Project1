//* * * * * * * * * * * * * * * *
//
//	
//	CS 210 A01
//
//	11/14/2010
//
//* * * * * * * * * * * * * * * * 

/* This program is designed to calcualte the number and type of bills an ATM would output to a customer to give them a specific amount of money in multiples of 10*/
#include <stdio.h>

int get_data (int *cash);

int dispense_bills ( int cash, int *fifties, int *twenties, int *tens);

int print_bills (int cash, int fifties, int twenties, int tens);

int main(void)
{

	int inp,	/* Input from user*/
	    five,	/* numer of fifties*/
	    two,	/* number of twenties*/
	    one;	/* number of tens*/
	char ans;	/* loop control */

	ans= 'Y';	/* priming value*/

	while( ans =='Y' || ans =='y'){

		get_data(&inp);

		dispense_bills(inp, &five, &two, &one);

		print_bills(inp, five, two, one);

		printf("\nWould you like to process another transaction? Y/N\n");
		scanf (" %c", &ans);
	}
	return (0);
}

int get_data(int *cash)
{
	
	printf ("Enter the desired amount to be withdrawn in an interval of $10\n");
	scanf ("%d", cash);


	while (*cash % 10 !=0){
		printf("\nThe value you entered is not valid, enter another value\n");
		scanf ("%d", cash);
	}
	return(0);
}

int dispense_bills(int cash, int *fifties, int *twenties, int *tens)
{
	int remain20,
	    remain10;

	if (cash %50 == 0){
		*fifties = cash / 50;
		*twenties = 0;
		*tens=0;
		}
	else if (cash %20 == 0){
		*fifties = cash / 50;
		remain20 = cash % 50;
		*twenties = remain20 / 20;
		remain10= remain20%20;
		*tens= remain10/10;
		}
	else if (cash %10 == 0){
		*fifties= cash/50;
		remain20=cash%50;
		*twenties= remain20/20;
		remain10= remain20%20;
		*tens=remain10/10;
		}
		return(0);
}

int print_bills (int cash, int fifties, int twenties, int tens)

{
	printf("\nThe amount you are withdrawing = $%d\n", cash);
	printf("***TAKE YOUR MONEY HONEY***");
	printf( "%d fiftie(s), %d twentie(s), %d ten(s)\n", fifties, twenties, tens);
	return(0);
}

/*******************************************************************************
This program will allow the user to tell a machine how much money they want to
take out (in intervals of $10). The program will then tell the bank machine
the amount to give to the user, with $50 bills, $20 bills, and $10 bills.

bills.c

Assignment 5
11/15/2010
*******************************************************************************/

#include <stdio.h>
#include <math.h>


void get_data(int *amount);
//gets the amount of money enetered by the user
//pre-condition: amount contains the address of a cell where the results are stored
//post-condition: the function stores the result in a cell which is pointed to amount

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);
//computes the amount of 50's, 20's, and 10's
//pre-condition: amount is defined, fifties, twenties, and tens contain addresses of a location
//post-condition: results are stored in a cell which are pointed to by fifties, twenties, and tens

void printBills(int amount, int fifties, int twenties, int tens);
//prints the results, the number of 50's , 20's, and 10's

int main(void)
{
	//declare the variables

	//add loop

	{
		//have the user enter the desired amount


		get_data(&amount);

		//divide the amount by 50, 20, & 10
		dispenseBills(amount, &fifties, &twenties, &tens);

		//print the amount and the number of 50's, 20's, and 10's
		printBills(amount, fifties, twenties, tens);
		//ask user if they want another transaction
		printf("Do you want another transaction? (y/n)?");
		scanf("%c", &another_trans);

			if ( another_trans == 'Y' || another_trans == 'y') {

	} //ends the loop

	return 0;
}

void get_data(int *amount)
{
	//ask the user to input the amount of cash they need
	printf("How much cash do you need? $");
	scanf("%d", amount);

	while (*amount % 10 != 0)
	{
		//tells the user that the machine can only dispense 50, 20, 10
		printf("This machine dispense ONLY $50, $20, $10");
		printf("Please enter amount again $");
		scanf("%d", amount);
	}
}
void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
	int twen_amoun;
	int ten_amoun;

	*fifties = amount / 50;

	twen_amoun = amount - (amount/50);

	*twenties = twen_amoun / 20;

	ten_amoun = twen_amoun - (twen_amoun/20);

	*tens = ten_amoun / 10;
}
void printBills(int amount, int fifties, int twenties, int tens)
{
	//set the variables
	char another_trans;

	//print the amount the user has inputed to take out
	printf("The amount you are withdrawing = %d", amount);
	//tell the user to take their cash
	printf("***Take Your Cash as $$$ bills***");
	//output the amount of 50's, 20's, and 10's
	printf("%d fifties %d twenties %d tens", fifties, twenties, tens);


}

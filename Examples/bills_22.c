//***************************************************************************
//
//  Name: 
//
//  E-mail: 
//
//  PID: P001214828
//
//  Date: november 11th  2010
//
//  Program: assignment5.c
//
//  Description: this program acts as an atm 
//
//**************************************************************************

#include<stdio.h>

void get_data(int *num);
 /* gets the number entered by the user
    pre- num contains the adress where the result is stored 
    post- func stores the result in a cell pointed by the number 
 */

void fifties_twenties_tens(int num, int *fift, int *twent, int *ten);
 /* divides the amount into three bills 
    pre- num is defined as a number of tens, twenties and fifties
    post- results are stored in cells pointed to tens, twenties and fifties
 */

void print(int num, int fift, int twent, int ten);
 /* prints the result- amount withdrawn 
    amount of tens 
    amount of twenties 
    amount of fifties
 */

int main(void)
{

	int amount;    /* input the amount entered by the user */
	int fifties;   /* number of fifties */
	int twenties;  /* number of twenties */
	int tens;      /* number of tens */

	char ans= 'Y';  /* the users response to another transaction */

	while (ans == 'Y' || ans == 'y'){
		
		get_data(&amount);
		
		fifties_twenties_tens(amount, &fifties, &twenties, &tens);
		
		print(amount, fifties, twenties, tens);
		
		printf("Do you want another transaction (Y/N)  ");
		scanf(" %c", &ans);
}
return(0);
}


void get_data(int *num)
{
	printf("Enter how much cash you need:  $ ");
	scanf("%d", num);
	
	while (*num%10 !=0)
	{
	 printf("This machine dispenses ONLY   $50, $20, $10...");
         printf("Please enter again ");
	 scanf("%d",num);
	}
	
}


void fifties_twenties_tens(int num, int *fift, int *twent, int *ten)
{
	*fift = num/50;
	*twent= num%50/20;
	*ten = num%50%20/10;
}
void print(int num, int fift, int twent, int ten)
{
	printf(" \n The amount you are withdrawing  =   $%4d\n",num);
	printf(" *** Take your Cash as $$$ bills ***\n");
	printf(" %d fifty %d twenties and %d tens\n",fift,twent,ten);
}






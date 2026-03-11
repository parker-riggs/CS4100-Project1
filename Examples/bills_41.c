//***********************************
//  Name: 
//
//  Date: 11-10-10
//
//  Decription: This program is sort of ran like an ATM machine. Dispensing money to a user with the least amount of bills being given out.
//
//  Email:
//
//
//
//*************************************

#include <stdio.h>

void get_data(int *amount);

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);

void printBills(int amount, int fifties, int twenties, int tens);

int main(void)
{
	char c = 'Y';
	int amo,
	    fif,
	    twe,
	    ten;
	    

	while (c == 'Y' || c == 'y'){
  
	get_data(&amo);
 
	dispenseBills(amo, &fif, &twe, &ten); 
 
	printBills(amo, fif, twe, ten);
  
	printf(" Another calculation Y/N  ");
	scanf(" %c",&c);
 }
  
   
    return(0);

}

void get_data(int *amount)
{
	int NUM,
	    num;

	printf("Enter the amount of cash that you need => \n");
	scanf("%d",&num);
	
	NUM = num % 10;
	if (NUM == 0)
	*amount = num;

	else {
	printf("This machine only dispenses $50, $20, $10...\n");
	printf("Please enter again > \n");
	scanf("%d",&num);}
	
	
}

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
	int extra,
	    extraB;
	
	if (amount >= 50)
	{	
	*fifties = amount / 50;
	extra = amount - (*fifties * 50);
		if (extra > 10){
		*twenties = extra / 20;
		extraB = extra - (*twenties * 20);
		*tens = extraB / 10;}
		else{
		*twenties = 0;
		*tens = extra / 10;}
	}
	else if ((amount < 50)&&(amount > 10))
	{
	*fifties = 0;
	*twenties = amount / 20;
	extraB = extra % 20;
	*tens = extraB / 10; 
	}
	else
	*fifties = 0;
	*twenties = 0;
	*tens = amount / 10;
} 

void printBills(int amount, int fifties, int twenties, int tens)
{
	printf("\n***** Take Your Cash As $$$ Bills *****\n");
	printf("%d fifty(s) %d twenty(ies) %d ten(s) \n\n\n\n",fifties,twenties,tens);
} 
	 
	   

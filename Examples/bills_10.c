//*******************************************************************************
//
// Program Name: Bills.c
//
// Name: 
// Email: 
//
// Description: This is a program for an automatic teller machine that dispenses
//             money. The user should enter the amount desied(a multiple of 10 
//             dollars) and the machine dispenses this amount using the least 
//             number of bills.
//
// Date: Nov 9,2010
//*******************************************************************************
#include<stdio.h>

void get_data(int *num);
/* gets the number entered by the user
	pre-num contains an address of a memonry cell where the results are to be
	    stored.
	post-function stores the result in cell pointed to by num */


void dispenseBills(int num,int *fif,int *twe,int *ten);
/*dispense the bills in to fifties, twentiesm and tens
	pre-num is definedm fif, twe, ten contain an addresses of a locations
	post-results are stored in cell pointed to by fif twe and ten */


void printBills(int num,int fif, int twe, int ten);
/*prints the results- the orginal number , the fifties, the twenties and tens part*/


int main(void)
{
	int amount, /*input-value entered by the user*/
	    fifties,   /*fifties part of the amount*/
	    twenties,  /*twenties part of the amount*/
	    tens;      /*tens part of the amount*/
	char ans;  /*the users response*/

	ans='Y';
	while(ans=='Y'||ans=='y')
	{
		/*Enter the desired amount. if the amount is incorrect 
		  (not a multiple of 10) give the user a chance to renenter
		   the Amount */

		get_data(&amount);
		
		// Divide the amount into number of 50's 20's and 10's bills
	
		dispenseBills(amount, &fifties, &twenties, &tens);

		// Print the amount and the number of 50's 20's and 10's bills

		printBills(amount, fifties, twenties, tens);
              
		printf("\nDo you want another transaction(y/n)? \n");

		scanf(" %c",&ans);
	
	}

	return (0);
}

void get_data (int *num)
{
	int val; /*local variable -value entered by the user*/
	int remain; /*local variable -value of the remainder of val divided by 10*/

	printf("Enter how much cash do you need? $ ");
	scanf("%d",&val);
	remain=val%10;

	while(remain != 0)
	{
		printf("This machine dispenses ONLY $50, $20, $10...\n");
		printf("Please enter again\n");
		scanf("%d",&val);

	        remain=val%10;
	}
	*num=val;
}

void dispenseBills(int num,int *fif,int *twe,int *ten)
{
	if(num>=50)
	{ *fif=num/50;
	  *twe=num%50/20;
	  *ten=num%50%20/10;
	}
	else if(num<50 && num>=20)
	{ *fif=0;
          *twe=num/20;
	  *ten=(num-*twe*20)/10;
	}
	else
	{ *fif=0;
	  *twe=0;
	  *ten=1;
	}
}

void printBills(int num,int fif,int twe,int ten)
{
	printf("\nThe amount you are withdrawing = $ %d\n",num);
	printf("\n*** Take your cash as $$$ bills ***\n");
	printf("\n%d fifty %d twenties and %d tens\n",fif,twe,ten);
}

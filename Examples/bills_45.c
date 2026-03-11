//****************************************************
// name: 
// program: assignment 5
// date: 2010 11 07
// description: this is a program for an autometic teller machine
//              that dispenses money.
//****************************************************

#include<stdio.h>
void get_data(int *amount);
/* pre: to get the input value
   post: output the value users entered*/
void dispensebills(int amount,int *fifties,int *twenties,int *tens);
/*pre: input the amount value
  post: output values to pointers*/
void printbills(int amount,int fifties,int twenties,int tens);
/*pre: input values defined
  post: print out all values*/

int main(void)
{

int amount, fifty,twenty,ten;
char yn='y';
   
while(yn=='y'||yn=='Y')
 {
	get_data(&amount);
	dispensebills(amount,&fifty,&twenty,&ten);
	printbills(amount,fifty, twenty,ten);

	printf("\nDo you want another transaction (Y/N)?");
	scanf(" %c",&yn);
    }

return(0);
}


void get_data(int *amount) 
{
double rem;
printf("Enter hou much cash do you need?  $");
scanf("%d",amount);
rem=*amount%10;
while(rem!=0)
 {
	printf("\nThis machine dispenses ONLY $50,$20,$10");
	printf("\nPlease enter again $");
	scanf("%d",amount);
	rem=*amount%10;
	}

}

void dispensebills(int amount,int *fifties,int *twenties,int *tens)
{
*fifties=(int)amount/50;
*twenties=(int)(amount%50)/20;
*tens=((amount%50)%20)/10;
}

void printbills(int amount,int fifties,int twenties,int tens)
{
printf("\nThe amount you are withdrawing= %d", amount);
printf("\n***Take your cash as bills***");
printf("\n %d fifty %d twenties %d tens",fifties,twenties,tens);
}

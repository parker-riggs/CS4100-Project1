//***********************************
//   program: assignment 5 
//   Name: 
//   description: The user should enter the
//   amount desired (a multiple of 10 dollars) and the machine dispenses this amount using the least number of bills.
//   The bills dispensed are 50s, 20s, and 10s.
//   Date :11/14/2010
//**********************************


#include <stdio.h> 

void get_data(int *amount);
/* gets the number entered by the user */


void dispenseBills(int amount, int *fifties, int *twenties, int *tens);
/* seperate the number to three parts */


void printBills(int amount, int fifties, int twenties, int tens);
/* prints the results */


int main(void)
{
        int amount;     /* input - value entered by the user */
        int fifties;    /* output - number of fifties */
        int twenties;   /* output - number of twenties*/
	int tens;       /* output - number of tens*/
        char ans;       /* ask the user to enter again or not*/
         
        ans = 'Y';

	 while(ans == 'Y' || ans == 'y') {

	/*Enter the desired amount. If the amount is incorrect
	
	(not a multiple of 10) give the user a chance to reenter the

	mount */

	get_data(&amount);

	// Divide the amount into number of 50¡¯s 20¡¯s and 10¡¯s bills
	
	dispenseBills(amount, &fifties, &twenties, &tens);

	// Print the amount and the number of 50¡¯s 20¡¯s and 10¡¯s bills

	printBills(amount, fifties, twenties, tens);
	
	printf("Do you want another transaction (y/n)?\n ");
	
	scanf(" %c",&ans);


	}
     
return 0;

} 


void get_data(int *amount)
{
  printf(" Enter how much cash do you need?  ");
  scanf("%d", amount);  

  while (*amount % 10 != 0)
  {
    printf("This machine dispenses ONLY $50, $20, $10...\nPlease enter again  ");
    scanf("%d", amount);
  }
}

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{       

	*fifties = amount / 50;
        *twenties = amount % 50 / 20;
        *tens = (amount % 50 - 20 * *twenties) / 10;
      
}

void printBills(int amount, int fifties, int twenties, int tens)
{
  printf(" \nThe amount you are withdrawing = %d\n",amount);
  printf(" *** Take your Cash as $$$ bills ***\n");
  printf(" %d fifty %d twenties and %d tens\n\n",fifties, twenties, tens);
}



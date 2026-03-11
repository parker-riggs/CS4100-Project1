/*11/14/2010. P001264328.  This program will return to the user the correct bills that the user needs based on how much money they need from the atm.*/


#include <stdio.h>

int get_data(int *amount)
	{ printf("Enter the amount of cash you need:");
	  scanf("%d",amount);

	  while(*amount % 10 != 0)
		{printf("This machine dispenses ONLY $50, $20, $10\n");
		 printf("Please enter again:");
		 scanf("%d",amount);
		}
	  return(0);
	}

int dispenseBills(int amount,int *fifties, int *twenties,int *tens)
	{  int rem_20,
	       rem_10;

	   if(amount % 50 == 0)
		{*fifties = amount / 50;
	  	 *twenties = 0;
		 *tens = 0;  
	   	}
	   else if(amount % 20 == 0)
		{*fifties = amount / 50;
		 rem_20 = amount % 50;
		 *twenties = rem_20 / 20;
		 rem_10 = rem_20 % 20;
		 *tens = rem_10 / 10;
		}
	   else
		{*fifties = amount / 50;
		 rem_20 = amount % 50;
		 *twenties = rem_20 / 20;
		 rem_10 = rem_20 % 20;
		 *tens = rem_10 / 10;
		}
	   return(0);
	}

int printbills(int amount, int fifties, int twenties, int tens)
	{ printf("The amount you are withdrawing is %d\n",amount);
	  printf("***Take your cash as $$$ bills***\n");
	  printf("%d fifty, %d twenty, %d ten(s)\n",fifties, twenties, tens);
	
	  return(0);
	}

int main(void)
{

	int amount,   /* input for amount needed.*/
	    fifties,  /* output for number of fifties.*/
	    twenties, /* output for number of twenties.*/
	    tens;     /* output for number of tens.*/

	char letter;  /* input for yes or no.*/

	letter = 'y';

	while(letter == 'y' || letter == 'Y')
	   {	get_data(&amount);

		dispenseBills(amount,&fifties,&twenties,&tens);

		printbills(amount, fifties, twenties, tens);

		printf("Would you like to make another transaction (Y/N)");
		scanf(" %c",&letter);

	   }

	return(0);

}

//*************************
//
//
//Assingment 5
//15 November 2010
//*************************

#include <stdio.h>
#include <math.h>

void get_data(int *a);

int depense_bills(int a, int *b, int *c, int *d);

void print_bills(int b, int c, int d);

int main(void)
{
   int amount;
   int fifty;
   int twenty;
   int ten;
   char ans = 'y';

   while (ans == 'Y' || ans == 'y')
   {
	get_data (&amount);
	
	despense_bills (amount, &fifty, &twenty, &ten);

	print_bills (fifty, twenty, ten);

	printf("Would you like to make another transaction? Y/N ");
	scanf(" %c",&ans);

   }
   return (0);
}

void get_data(int *amt)
{
   

   printf("\nPlease enter how much cash you need? $");
   scanf("%d", amt);

   while (*amt % 10 != 0)
   {
	printf("\nThis machine only depenses $50, $20, and $10.\n");
	printf("Please try again. $");
	scanf("%d", amt);
   }

   printf("\nThe amount you are withdrawing = $ %d", *amt);
}

int despense_bills(int amt, int *ffty, int *twnty, int *tn)
{
   int fftyp = 0;
   int twntyp = 0;
   int tnp = 0;

   while (amt > 0)
   {
	if (amt >= 50)
	{
	   fftyp += 1;
	   amt -= 50;
	}
	
	else if (amt >= 20)
	{
	   twntyp += 1;
	   amt -= 20;
	}

	else
	{
	   tnp += 1;
	   amt -= 10;
	}

   }

  *ffty = fftyp;
  *twnty = twntyp;
  *tn = tnp; 
}

void print_bills(int ffty, int twnty, int tn)
{
   printf("\n*** Take your cash as $$$ bills ***\n");
   printf("%d fifties, %d twenties, %d tens\n\n", ffty, twnty, tn);
}

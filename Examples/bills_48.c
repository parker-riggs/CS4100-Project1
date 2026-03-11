
//*******************************************
//   Name: 
//   Email:
//   Date: 11/10/2010
//********************************************

#include <stdio.h>

void get_data(int *amo);
/* get the number entered by the user
    pre- num contains an address of a memory cell where the retiles are to be stored
    post- function stores the result in the cell pointed to by num
*/

void fifties_twenties_tens(int amo, int *fif, int *twe, int *ten);
/* separate the number to three parts
    pre- amo is defined. fife, twe, ten contain an addresses of a locations
    post- results are stored in cell pointed to by fif, twe, ten.
*/

void print (int amo, int fif, int twe, int ten);
/*prints the results- the number entered by the user, the number of fifties, twenties, tens
*/

int main(void)
{
   int amount;
   int fifties;
   int twenties;
   int tens;
 
  char and = 'Y'; /* the user response*/

 while (and == 'Y' || and == 'y' )
 { 
    get_data(&amount);

    fifties_twenties_tens(amount, &fifties, &twenties, &tens);

   print(amount, fifties, twenties, tens);

  printf("\n Do you want another transaction (y/n)? " );
  scanf( " %c", &and);
  
   }
 return 0;
}

void get_data(int *amo)
{ 
  
  printf("\nEnter how much cash do you need? $");
  scanf("%d", amo);

  while (((*amo)%10) != 0 )
  {
     printf("\n This machine dispenses ONLY $50, $20, $10\n");
     printf("\n please enter again $");
     scanf("%d",amo);
   }
  
}

void fifties_twenties_tens(int amo, int *fif, int *twe, int *ten)
{
 *fif=amo/50;
 *twe=(amo%50)/20;
 *ten=((amo%50)%20)/10;
 }

void print (int amo, int fif, int twe, int ten)
{
    printf(" \nThe amount you are withdrawing = $ %d\n",amo);
    printf("\n Take your cash as $$$ bills\n");
    printf("\n %d fifty %d twenties and %d tens\n", fif, twe,ten);
}
 


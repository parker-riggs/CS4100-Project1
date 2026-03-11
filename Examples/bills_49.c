//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//
//   Program name:   Bills
//   Name  :         
//   Email :         
//   Date  :         November 14
//   Description :   This program is for an automatic teller machine 
//                   that dispenses money.
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 
#include <stdio.h>

void get_data(int *num);
/* gets the number entered by the user
   pre - num contains an address of a memory cell where the results are 
         to be stored.
   post - function stores the result in cell pointed to by num */

void dispenseBills(int num, int *ft, int *tt, int *tn);
/* dispense the number to 50s, 20s, 10s
   pre - num is defined. ft, tt and tn contain an addresses of a 
         locations
   post - results are stored in cell pointed to by ft, tt and tn */

void printBills(int num, int ft, int tt, int tn);
/* prints the results - the orginal number, the fifties, the twenties 
and the tens */

int main(void)
{
  int amount;   /* input - the amount entered by the user */
  int fifties;  /* the 50s part of the whole amount */
  int twenties; /* the 20s part of the whole amount */
  int tens;     /* the 10s part of the whole amount */

  char ans = 'y';  /* the users response */

  while (ans == 'Y'  || ans == 'y'){
      
     get_data(&amount);

     dispenseBills(amount, &fifties, &twenties, &tens);

     printBills(amount, fifties, twenties, tens);
  
     printf("\nDo you want another transaction (y/n)? ");
     scanf(" %c",&ans);
  }

  return 0;
}

void get_data(int *num)
{
  printf("Enter how much cash do you need? $");
  scanf("%d", num);

  while ( *num % 10 != 0)
  {
    printf("This machine dispenses ONLY $50, $20, $10...\nPlease enter again $");
    scanf("%d", num);
   }
}

void dispenseBills(int num, int *ft, int *tt, int *tn)
{
  *ft = num / 50;
  *tt = (num - *ft * 50) / 20;
  *tn = (num - *ft *50 - *tt * 20) / 10;
} 

void printBills(int num, int ft, int tt, int tn)
{
  printf("The amount you are withdrawing = $ %d  \n",num);
  printf("*** Take your Cash as $$$ bills ***\n");
  printf("%d fifty %d twenties and %d tens \n",ft, tt, tn);
}



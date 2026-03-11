//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program :     assign5 bills.c
//
//   Name :        
//   Email:       
//
//   Description:  This program dispenses an amount entered by user  
//                 using the least number of bills.
//
//   Date :        Nov 12, 2010
//
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>

void get_data(int *money);
/* gets the amount of money entered by the user 
   pre - money contains an address of a memory cell where the
         results are to be stored.
   post -function stores the result in cell pointed to by money */


void dispenseBills(int money, int *fiftyp, int *twentyp, int *tenp);
/* dispense the money into three types of bill
   pre - money is defined. fiftyp, twentyp and tenp
         contain an addresses of a location 
   post - results are stored in cell pointed to by 
          fiftyp, twentyp and tenp  */


void printBills(int money, int fiftyp, int twentyp, int tenp);
/* prints the results - the orginal amount of money, the number of 
   fifty bills, twenty bills and ten bills */

int main(void)
{
    int amount,            /* input - value entered by the user */
        fifties,           /* output - number of fifty bills    */
        twenties,          /* output - number of twenty bills   */
        tens;              /* output - number of ten bills      */

    char ans= 'y'; /* the users response */

    while (ans == 'Y' || ans == 'y')
    {
  
	get_data(&amount);

        dispenseBills(amount, &fifties, &twenties, &tens);
 
	printBills(amount, fifties, twenties, tens);
  
	printf(" Do you want another transaction (y/n)? ");
	scanf(" %c",&ans);
    }
  
    return 0;
}


void get_data(int *money)
{
    printf(" Enter how much cash do you need-->  $");
    scanf("%d", money); 

    while (*money % 10 != 0)
    {
       printf(" This machine dispenses ONLY $50, $20, $10...\n");
       printf(" Please enter again $");    
       scanf("%d", money);
    }
}


void dispenseBills(int money, int *fiftyp, int *twentyp, int *tenp)
{
    *fiftyp = money / 50;
    *twentyp = money % 50 / 20;
    *tenp = money % 50 % 20 / 10;
}


void printBills(int money, int fiftyp, int twentyp, int tenp)
{
    printf(" The amount you are withdrawing = $ %d \n", money);
    printf("\n *** Take your Cash as $$$ bills *** \n");
    printf(" %d fifty %d twenties and %d tens\n\n", fiftyp, twentyp, tenp);
}


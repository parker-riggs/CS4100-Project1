/****************************************************
*
*  
*  section A04
*   11-7-10
*  assignment 5
*
*
*
*****************************************************/
#include <stdio.h>

void get_data(int *amountp);  /* gets the amount of money needed withdrawed */
void dispenseBills(int amountp,int *fiftyp, int *twentyp, int *tensp);  /* divides the amount into bills */

void printBills(int amountp,int fiftyp, int twentyp, int tensp); /* prints how many bills of each are dispensed */

int main(void) {
int amount, fifties, twenties, tens;
char ans= 'Y';   /* begins main function */

printf("\n\n");

  while (ans == 'Y' || ans == 'y'){    /* while loop to keep program going until user no longer wants to use the atm */

get_data(&amount); 

dispenseBills(amount, &fifties, &twenties, &tens); 

printBills(amount, fifties, twenties, tens);

printf("\n\n Do you want another transaction?(y/n)");
scanf(" %c",&ans);
}

return 0;
}

void get_data(int *amountp)
{

printf("Enter how much cash do you need in multiples of 10 >");
scanf("%d",&*amountp);

while(*amountp % 10 != 0)  /* makes sure that the user enters an amount in multiples of 10 */
{
printf("This machine only dispenses in multiples of 10, please enter again >");
scanf("%d",&*amountp);
}
}
void dispenseBills(int amountp, int *fiftyp, int *twentyp, int *tensp)
{
/* divides the amount up into appropriate number of each bill, updates amount */
*fiftyp = amountp / 50;
amountp = amountp % 50;
*twentyp = amountp / 20;   
amountp = amountp % 20;
*tensp = amountp / 10;
}

void printBills(int amountp, int fiftyp, int twentyp, int tensp)
{
printf("The amount you are withdrawing = $%2d \n",amountp);
printf("***Take your cash as $$$ bills ***\n");
printf("%d fifty %d twenties %d tens \n\n", fiftyp,twentyp,tensp);

}


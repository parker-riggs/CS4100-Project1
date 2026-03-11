/***************************************************************************
	NAME: 
	SECTION: CS 210 A04
	DATE: NOV 13, 2010
	PROGRAM: BILLS.C
	DESCRIPTION: DISPENSE MONEY INTO THE LEAST BILLS
**************************************************************************/

#include<stdio.h>

void get_data(int *num);
/* gets the number from the user and test it if meets the reqiurment
   pre - num contains an address of a memory cel where the results are 
         to be stored
   post -function stores the result in cell pointed to by num
*/

void dispensebills(int num, int *ffy, int *twn, int *ten);
/* dispense the number to three parts
   pre- num is defined by the user. ffy, twn and ten contain an 
        addresses of locations
   post- results are stored in cells pointed to by ffy, twn and ten
*/

int main(void)
{
int amount, ffty, twny, tens;
char sign;
sign = 'Y';

while(sign=='Y'||sign=='y')
 {
  get_data(&amount);
  dispensebills(amount, &ffty, &twny, &tens);
  printf("\n***\tThanks for waiting\t ***\n"); 
  printf("  The amount you are withdrawing = %d",amount);
  printf("\n ***Take your cash as $$$ bills ***\n"); 
  printf("%d fifty %d twenty and %d ten",ffty, twny, tens);
  printf("\nDo you need another transaction (y/n)? -->");
  scanf(" %c",&sign); 
 }

return 0;

}

void get_data(int *num)
{
  printf("\nEnter how much cash do you need? -->");
  scanf("%d", num);
  while(*num%10 != 0)
  {
   printf("\nThis machine dispenses ONLY $50, $20, $10...");
   printf("\nPlease enter again -->");
   scanf("%d",num);
  } 
}

void dispensebills(int num,int *ffy,int *twn,int *ten)
{
 *ffy= num/50;
 *twn= (num%50)/20;
 *ten= ((num%50)%20)/10;
}

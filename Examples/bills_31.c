/*Name: 
 * Email
 * Date: 11/11/10
 * program: Bills.c assign5
 */


#include <stdio.h>
#include <math.h>

void get_data(int *num);
/* gets the number entered by the user
      pre - num contains an address of a memory cell where the
               results are then stored.
      post -stores the result in cell pointed to by num */

void dispensebills(int num, int *fif, int *twen, int *ten);
/*Divides the amount into number of 50.s 20.s and 10.s bills
  pre- seperates fif, twen, and ten
  post- points to fif, twen, ten*/

void printbills(int num, int fif, int twen, int ten);
/*prints the amount and the number of 50.s 20.s and 10.s bills*/



int main(void)
{
  int amount; /*input amount from user*/
  int fifties;
  int twenties;
  int tens;

  char res = 'Y';/*response to character 'yes'*/

  while (res == 'Y' || res == 'y')
    {
      get_data(&amount);

      dispensebills(amount, &fifties, &twenties, &tens);

      printbills(amount, fifties, twenties, tens);

      printf("Do you want another transaction? y/n \n");
      scanf(" %c", &res);
    }

  return 0;

}

void get_data(int *num)
{
  int val; /* local variable - value entered by the user */

  printf(" Enter how much cash do you need? ");
  scanf("%d", &val);

  val=val % 10;

  while (val != 0)
    {
      printf("This machine dispenses ONLY $50, $20, $10...\n");
      printf("Please enter again ");
      scanf("%d", &val);
    }

  *num = val;
}

void dispensebills(int num, int *fif, int *twen, int *ten)
{

  if (num >= 50){
    num = num / 50;
    *fif = num;
  }
  else if (num >= 20 && num < 50){
    num = num / 20;
    *twen = num;
  }
  else if (num >=0 && num < 20){
    num = num / 10;
    *ten = num;
  }
}

void printbills(int num, int fif, int twen, int ten)
{
  printf("The amount you are withdrawing %d \n", &num);
  printf("*** Take your Cash as $$$ bills ***\n");
  printf(" %d fifties %d twenties and %d tens\n", &fif, &twen, &ten);
}

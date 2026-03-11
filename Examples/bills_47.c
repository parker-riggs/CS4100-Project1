#include <stdio.h>
#include <math.h>

void get_data(int *cash);
/* gets the number entered by the user 
   pre - num contains an address of a memory cell where the
         results are to be stored.
   post -function stores the result in cell pointed to by num */


void seperate(int cash, int *fif, int *twe, int *ten);
/* seperate the number to three parts
   pre - num is defined. signp, wholep and fracp
         contain an addresses of a locations 
   post - results are stored in cell pointed to by 
          signp, wholep and fracp  */


void print(int cash, int fif, int twe, int ten);
/* prints the results - the orginal cash, the number of fifty, twety and ten dollars will include */

int main(void)
{
  int value;    /* input - value of cash entered by the user */
  int fith;     /* number of fifty dollars will be included */
  int twth;     /* number of twety dollars will be included */
  int teth;     /* number of ten dollars will be included */

  char ans= 'Y'; /* the users response */

  while (ans == 'Y' || ans == 'y'){
  
	get_data(&value);
 
	seperate(value, &fith, &twth, &teth); 
 
	print(value, fith, twth, teth);
  
	printf(" Do you want another transaction (Y/N)? ");
	scanf(" %c",&ans);
 }
  
  return 0;
}

void get_data(int *cash)
{
  printf(" Enter how much cash do you need? $");
  scanf("%d",cash); 
  

  while (*cash % 10 != 0)
  {
    printf(" This machine dispenses ONLY $50, $20, $10... \n");
    printf(" Please enter again. $");
    scanf("%d",cash);
  }
   

}

void seperate(int cash, int *fif, int *twe, int *ten)
{
 
  *fif = cash / 50;
  *twe = (cash % 50) / 20;
  *ten = ((cash % 50) % 20) / 10;

}

void print(int cash, int fif, int twe, int ten)
{
  printf(" The amount you are withdrawing = $ %d\n", cash);
  printf(" *** Take your Cash as $$$ bills ***\n");
  printf(" \n %d fifth %d twenties %d tens.\n\n", fif, twe, ten);
  
}


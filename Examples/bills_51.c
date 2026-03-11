/* 
* nov. 15 2010
* dispense bills
*/




#include <stdio.h>
#include <math.h>

void get_data(double *num);
/* gets the number entered by the user 
   pre - num contains an address of a memory cell where the
         results are to be stored.
   post -function stores the result in cell pointed to by num */


void dispenseBills(double num, double *fif, double *twe, double *ten);
/* seperate the number to three parts
   pre - num is defined. fif, twe and ten
         contain an addresses of a locations 
   post - results are stored in cell pointed to by 
          fif, twe and ten  */


void printBills(double num, double fif, double we, double ten);
/* prints the results - the orginal number, amount of fifties , amount of twenties and the amount of tens */
  

int main(void)
{
  double amount; /* input - value entered by the user */
  double fifties;     /* amount of fifties needed */
  double twenties;    /* amount of twenties needed */
  double tens; /* amount of tens needed */
   
  char ans= 'Y"; /* users response */

  while (ans == 'Y' || ans == 'y'){
  	
	/* Enter the desired amount. if the amount is incorrect (not a 		multiple of 10) five the user a chance to reenter the amount*/
	get_data(&amount);
 
	// Divide the amount into number of 50's 20's and 10's bills
	dispenseBills(amount, &fifties, &twenties, &tens); 
 
	// Print the amount and the number of 50's 20's and 10's bills
	printBills(amount, fifties, twenties, tens);
  
	printf(" Another Transaction Y/N  ");
	scanf(" %c",&ans);
 }
  
  return 0;
}


void get_data(double *num)
{
  double amt; /* local variable - value entered by the user */

  do {printf(" Enter the amount of cash you need -->   ");
  scanf("%lf",&amt); 
	}if( amt == '10' || amt == '20' || Amt == '30'|| Amt == '40' ||Amt == '50' || Amt == '60' || Amt == '70' || Amt == '80' || Amt == '90' || Amt == '100' ) {
	printf("The amount you are withdrawing = %f", amt);

}  
    else if{
	printf("This machine dispenses ONLY $50, $20, $10É/n");
	printf("Please enter again");
	scanf("%lf", &amt);
   
   
    
  }

  *num = amt;   

}

void dispenseBills(double num, char *fif, int *twe double *ten)
{
  double bill; /* local variable - magnitude of num */

  if (num == '50')
    *fif = '1';
	else if( num =='100')
	*fif ='2';
  	else if (num == '20'  )
    *twe = '';

 

}


void print(double num, double if, double we, double ten)
{
  printf(" \nAmount %.4f  \n",amt);
  printf(" Fifties:  %c \n",fif);
  printf(" Twenties:  %d \n",twe);
  printf(" Tens: %.4f\n\n",ten);
}


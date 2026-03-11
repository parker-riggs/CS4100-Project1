#include <stdio.h>

void get_data( int *amount);
/* gets the number entered by the user 
   pre - amount gets the number that is to be used throughout the program
   post -function test if the number entered is able to be evenly divided by ten.*/

void dispenseBills (int amount,int *fifties,int *twenties,int *tens);
/* separates the amount into fifties, twenties and tens
   pre- the number is entered and ran across all three pointer locations
   post- the number is show as fifties, twenties and tens.*/
void printBills (int amount,int fifties,int twenties,int tens);
/* Prints out the output of the dispenseBills function*/
int main(void)
{
int number;/*The amount entered*/
int fif;/*amount of fifties*/
int twen;/*amount of twenties*/
int ten;/*amount of tens*/
char ans= 'Y'; /* the users response */

	 while (ans == 'Y' || ans == 'y'){
  
	get_data(&number);
        dispenseBills (number, &fif, &twen, & ten);
 	printBills (number, fif,twen,ten);

	printf("The amount you are withdrawing $ %d\n",number);
	
	printf(" Another calculation Y/N  ");
	scanf(" %c",&ans);}
	


	return 0;
}



void get_data( int *amount)

{
	printf("Please enter the amount of cash you wish to recieve $  ");
	scanf("%d",amount);

   while (*amount % 10 !=  0){
   printf("Amount is not valid. This machine dispenses only in $50, $20, $10\n");
   printf("Please enter again $ ");
   scanf("%d",amount);}
}

void dispenseBills (int amount,int *fifties,int *twenties,int *tens)
{ int a, b;
  
 *fifties = amount/ 50;
   a = amount % 50;
 *twenties = a/ 20;
   b = *twenties/20; 
  *tens = *twenties / 10; 


} 
void printBills (int amount,int fifties,int twenties,int tens)
{

printf("*** Take your cash as $$$ bills ***\n");
printf("fifty %d ",fifties);
printf("twenties %d ",twenties);
printf("tens %d \n",tens);
}



























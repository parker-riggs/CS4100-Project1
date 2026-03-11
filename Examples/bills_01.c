/* 
  This program allows the user to enter the amount of money in they would like to receive and the machine will dispense that amount using the least 
  amount of bills as possible.*/

#include<stdio.h> 
#include<math.h>

void get_data(int *num);
/*gets number entered by user
 pre: num contains address of a memory cell where results are to be stored
 post: function stores result in cell pointed to by num
*/
void dispensebills(int num, int *fifties1, int *twenties1, int *tens1);
/*divides amount into 10s, 20s and 50s
 pre: num is defined. fifties1, twenties1 and tens1 contain addresses of locations
 post: results are stored in cells pointed to by fifties1, twenties1 and tens1
*/
void printbills(int num, int fifties1, int twenties1, int tens1);
/*prints the results-the original amount, the amount of fifties, the amount of twenties and the amount of tens
*/

int main(void)
{
int amount; /* input amount of money desired */
int tens; /*output amount of tens */
int twenties; /* output amount of twenties*/
int fifties; /* output amount of fifties */

char ans = 'Y' ; /*users response*/

while (ans == 'Y' || ans == 'y')
{
get_data(&amount);

dispensebills(amount, &fifties, &twenties, &tens);

printbills(amount, fifties, twenties, tens);

printf("Another Transaction? Y/N");
scanf("%c", &ans);
} 

return (0);
}

void get_data (int *num)
{
printf ("Enter amount of money>");
scanf("%d", num);

	while (*num !=  modul 10)
	{
	printf("This machine dispenses only $50, $20, $10...\n Please Enter Again $");
	scanf("%d", num);
	}
}

void dispensebills (int num, int *fifties1, int *twenties1, int *tens1)
{
   if (num >= 50)
    *fifties1>=1;
   else if (num >= 20)
    *twenties>=1;
   else
    *tens>=1;
}

void printbills (num, fifties1, twenties1, tens1)
{
   printf("the amount you are withdrawing-$%d", num);
   printf("%d fifties %d twenties %d tens", fifties1, twenties1, tens1); 
}

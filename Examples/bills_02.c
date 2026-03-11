// * * * * * * * * * *
// 
// Assignment # 5
// Section A04
// Nov 14 210
// * * * * * * * * * *

#include<stdio.h>

void get_data(int *requested);
void dispenseBills(int amount, int *large, int *medium, int *small);
void printBills(int amount, int fifties, int twenties, int tens);


int
main (void)
{
	char repeat;			/* input - loop control variable	*/
	int amount;			/* input - amount wanted by user	*/
	int fifties;			/* ouput - number of fifties received	*/
	int twenties;			/* ouput - number of twenties received  */
	int tens;			/* ouput - number of tens received	*/

	
	do{	
	
		get_data(&amount);

		dispenseBills(amount, &fifties, &twenties, &tens);

		printBills(amount, fifties, twenties, tens);


	        printf("Do you want another transaction (y/n)?");
	        scanf(" %c", &repeat);
	  
	  } while(repeat == 'y' || repeat == 'Y');	

		
return (0);
}

 /* Gets data from user and checks for faulty inputs
 * 
 * Pre: Requested is pointed to cell in main
 * 
 * Post: Value returned through pointer to cell 
 * 
 */

void get_data(int *requested)
{

	
 	int value;      /* Value entered by user */

        printf("Enter how much cash you need >  ");
        scanf("%d", &value);

        while(value % 10 != 0)
        {

                printf("This machine dispenses ONLY $50, $20, $10...\n");
                printf("Please enter again >  ");
                scanf("%d", &value);
        }

 *requested = value;

}

 /* Seperates into least amount of Bills possible
 *
 * Pre: Amount given by user, others point to addresses of cells in main
 * 
 * Post: Results stored in cells pointed to by *large, *medium, and *small
 * 
 */

void dispenseBills(int amount, int *large, int *medium, int *small)
{

	int num_fifties;		/* ouput - number of fifties received   	*/	
	int num_twenties;		/* ouput - number of twenties received  	*/
	int num_tens;			/* ouput - number of tens received      	*/
	int left;			/* Amount left after number fifties removed 	*/
	int remain;			/* Amount left after tens removed		*/			

	num_fifties = amount / 50;
	left = amount % 50;

	num_twenties = left / 20;
	remain = left % 20;

	num_tens = remain / 10;
  
	*large = num_fifties;
	*medium = num_twenties;
	*small = num_tens;
}

 /* Gets all input data from main with no outputs
 *
 * Pre: All parameters are input 
 *
 * Post: Void function. No value returned.
 */

void printBills(int amount, int five, int two, int one)
{

				
	printf("The amount you are withdrawing = $  %d\n", amount);
	printf("*** Take Your Cash ***\n");
	printf("%d fifty  %d twenties  and  %d tens\n\n", five, two, one);


}

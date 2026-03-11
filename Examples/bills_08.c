//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//
//	Name:		
//	Program:	bills.c
//	Email:		
// 	Description:	Input and Output Parameters
//	Date:		November 15, 2010
//
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void get_data(int *amount);
/* precondition : amount contains an address of a memory cell where the results are to be stored
   postcondition : function stores the result in cell pointed to by num */

void dispenseBills(int amount, int *fifties, int *twenties, int *tens);
/* precondition : receives the amount desired by the user
   postcondition : separates the amount into fifties, twenties, and tens*/

void printBills(int amount, int fifties, int twenties, int tens);
/* precondition : takes information gathered from dispenseBills
   postcondition : prints the amount of fifties, twenties, and tens*/

int main(void)
{
	int amount;	/*amount entered by the user*/
	int fifties;	/*number of fifties*/
	int twenties;	/*number of twenties*/
	int tens;	/*number of tens*/
	char ans= 'Y';  /* the users response */

  	while (ans == 'Y' || ans == 'y'){
  	
	/*Enter the desired amount. If the amount is incorrect (not a multiple of 10) give the user a chance to reenter the 		amount*/
	get_data(&amount);

	/*Divide the amount into number of 50's 20's and 10's bills*/ 
	dispenseBills(amount, &fifties, &twenties, &tens); 
 	
	/*Print the amount and the number of 50's 20's and 10's bills*/
	printBills(amount, fifties, twenties, tens);
  
	printf("Do you want another transaction (y/n)?");
	scanf(" %c",&ans);
 	}
  
  	return 0;
}


void get_data(int *amount)
{
	printf("Enter how much cash do you need? $");
  	scanf("%d", amount);

  	while (*amount %10 != 0)
  	{
   	printf("This machine dispenses ONLY $50, $20, $10...\n");
	printf("\nPlease enter another amount $");    	
	scanf("%d", amount);
  	}
}

void dispenseBills(int amount, int *fifties, int *twenties, int *tens)
{
	int result;	/*result of division*/
	int left_over;	/*remaining amount after division*/
	
	*fifties = amount * 1/50;
	left_over = amount %50;
	
	*twenties = left_over * 1/20;
	result = left_over %20;
	
	*tens = result * 1/10;
}

void printBills(int amount, int fifties, int twenties, int tens)
{
	printf("The amount you are withdrawing = $ %d\n", amount);
	printf("*** Take your Cash as $$$ bills ***\n");
	printf("%d fifties %d twenties %d tens \n", fifties, twenties, tens);
}


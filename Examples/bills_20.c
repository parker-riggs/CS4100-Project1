/*
 * NAME:		
 * DATE:		6 Nov 2010
 * DESCRIPTION:	A user inputs the $ amount desired (multiple of 10), ATM 
 * 				dispenses that amount.
 * FILENAME:	bills.c
 */
#include <stdio.h>

/*
 * Finds the amount desired by user
 * Pre:  &amount passed to function
 * Post: amount stored
 */
void get_data(int *amount);

/*
 * Determines the no. of ea. kind of bill to be dispensed
 * Pre:  dollar amount given, ea. kind of bill defined
 * Post: no. of ea. bill type stored
 */
void dispense_bills(int amount, 		// 
					int *ten_note, 		// 
					int *twenty_note,	// 
					int *fifty_note);	// 

/*
 * Prints bills given to user
 * Pre:  amount, ten_note, twenty_note, fifty_note have values
 * Post: values of the above printed
 */
void print_bills(int amount,
				 int ten_note,
				 int twenty_note,
				 int fifty_note);

int
main(void)
{
	int		amount,				// amount desired by user
			ten_note,			// ten dollar bills
			twenty_note,		// twenty dollar bills
			fifty_note;			// fifty dollar bills
	char	another;			// y to exit, n for another transaction
	
	printf("\t\tW E L C O M E !\n");
	
	do {
		ten_note = 0;
		twenty_note = 0;
		fifty_note = 0;
		
		get_data(&amount);
		dispense_bills(amount, &ten_note, &twenty_note, &fifty_note);
		print_bills(amount, ten_note, twenty_note, fifty_note);
		
		printf("Would you like another transaction? (y/n) > ");
		scanf(" %c", &another);
	} while (another == 'y');
	
	return 0;
}

void
get_data(int *amount)
{
	/*
	printf("GET_DATA HERE, AMOUNT SET TO 500");
	*amount = 500;
	*/
	int valid_input,	// input validation
		input_status;	// is input an integer?
	char ch;			// char for invalid input
	
	do {
		printf("Please enter an amount > ");
		input_status = scanf(" %d", amount);

		if (input_status == 0) {
			scanf(" %c", &ch);
			printf("****ERROR Invalid input: '%c' ****\n", ch);
			valid_input = 0;
		} else if (*amount % 10 != 0){
			printf("Please give a multiple of ten.\n");
			valid_input = 0;
		} else {
			valid_input = 1;
		}
	} while (valid_input == 0);
}

void
dispense_bills(int amount,			// input, to be sorted
			   int *ten_note,		// output, $10 bills
			   int *twenty_note,	// output, $20 bills
			   int *fifty_note)		// output, %50 bills
{
	while (amount > 0) {
		if (amount >= 50) {
			*fifty_note += 1;
			amount -= 50;
		} else if (amount >= 20) {
			*twenty_note += 1;
			amount -= 20;
		} else {
			*ten_note += 1;
			amount -= 10;
		}
	}
}

void
print_bills(int amount, int ten_note, int twenty_note, int fifty_note)
{
	printf("\nThe amount you are withdrawing:	$ %d\n", amount);
	printf("%d fifties, %d twenties, and %d tens.\n\n", fifty_note, twenty_note, ten_note);
}

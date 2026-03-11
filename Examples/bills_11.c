#include <stdio.h>
#include <math.h>

void get_data(int *ammount);
void dispenseBills(double ammount, double *fifties, double *twenties, double *tens);
void printBills(double ammount, double fifties, double twenties, double tens);

int main(void)
{
	//Variable Definitions
	
	/* Iput: Ammount */
	int ammount;

	/* Output: Number of specific bills */
	double fifties, twenties, tens;

	/* Input: Loop Control */
	char loop_again;

	do
	{
		printf(" Perform a transaction (y/n):");
		scanf(" %c", &loop_again);

		if (loop_again == 'y' || loop_again == 'Y')
		{
			get_data(&ammount);

			dispenseBills(ammount, &fifties, &twenties, &tens);

			printBills(ammount, fifties, twenties, tens);
		}
	} while (loop_again == 'y' || loop_again == 'Y');

return 0;
}

void get_data(int *ammount)
{
	int check_it;
do
{
	printf("\n Enter the ammount to be sorted:$");
	scanf("%d", ammount);

	check_it = (*ammount % 10);

	if (check_it != 0)
	{
		printf("\n ERROR: Not a multiple of 10. Please try again. \n");
	}
}while (check_it != 0);
}

void dispenseBills(double ammount, double *fifties, double *twenties, double *tens)
{
	int temp_num1, temp_num2, temp_num3;

	temp_num1 = ammount / 50;
	temp_num2 = (ammount - temp_num1 * 50) / 20;
	temp_num3 = (ammount - (temp_num1 * 50) - (temp_num2 * 20)) / 10;

	*fifties = temp_num1;
	*twenties = temp_num2;
	*tens = temp_num3;
}

void printBills(double ammount, double fifties, double twenties, double tens)
{
	printf("The number of Fifties dispensed is: %.0f \n", fifties);
	printf("The number of Twenties dispensed is: %.0f \n", twenties);
	printf("The number of Tens dispensed is: %.0f \n", tens);
}

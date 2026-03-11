#include <stdio.h>


/* Function Prototypes */

void intro();

void get_data(int *amountp); /* gets the amount of money the user wants
   pre - amountp contains an address of a memory cell where the
         results are to be stored.
   post -function stores the result in cell pointed to by amountp */

void dispenseBills(int amount, int *fiftiesp, int *twentiesp, int *tensp);
/* splits the amount given by the user into 50s, 20s, and 10s.
   pre - fiftiesp, twentiesp, and tensp all contain an address of a memory cell where the
         results are to be stored.
   post -function stores the results in the cells pointed to by 
   fiftiesp, twentiesp, and tensp. */  

void printBills(int amount, int fifties, int twenties, int tens);
/* prints the results - the amount and how many of each bill will be taken out */

int main(void)
{
	int amo, /* The amount of money the user wants to take out */
		fif, /* The amount of 50 dollar bills the atm takes out */
		ten, /* The amount of 10 dollar bills the atm takes out. */
		twen;/* Tha amount of 20 dollar bills the atm takes out. */
	char ans = 'Y'; /* The user response */
	intro();
	while (ans == 'Y' || ans == 'y'){
		get_data(&amo);
		dispenseBills(amo,&fif,&twen,&ten);
		printBills(amo,fif,twen,ten);
		
		printf("Do you want another transaction (y/n)? ");
		scanf(" %c",&ans);
	}
	return(0);
}
void intro() {
	printf("This program is designed to be an ATM. The user tells the ATM\n");
	printf("how much he/she needs and the ATM takes the money out in 50, 20,\n");
	printf("and 10 dollar bills.\n\n\n");
}
void get_data (int *amountp) {
	int remainder,
		cash;
	printf("Enter how much cash you need > ");
	scanf("%d", &cash);
	remainder = cash % 10;
	while (remainder % 10 != 0)
	{
		printf("This machine dispenses ONLY $50, $20, $10...\n");
		printf("Please try again > ");
		scanf("%d",&cash);
		remainder = cash % 10;
	}
	*amountp = cash;
}	
void dispenseBills(int amount, int *fiftiesp, int *twentiesp, int *tensp) {
	int fifty = 0,
		twenty = 0,
		ten = 0;
	
	while(amount > 0) {
		
		if(amount >= 50) {
			fifty += 1;
			amount -= 50;
		}
		else if(amount >= 20){
			twenty +=1;
			amount -= 20;
		}
		else {
			ten += 1;
			amount -= 10;
		}
	}
	*fiftiesp = fifty;
	*twentiesp = twenty;
	*tensp = ten;
}
	
void printBills(int amount, int fifties, int twenties, int tens)

{
	printf("The amount you are withdrawing = $ %d\n", amount);
	printf("*** Take your Cash as $$$ bills ***\n");
	printf("%d fifties %d twenties %d tens\n\n\n", fifties, twenties, tens);
	
}

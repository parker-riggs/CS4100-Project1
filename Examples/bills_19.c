// * * * * *
// 
// bills.c
// 
// * * * * *

// included libraries
#include <stdio.h>

// included functions
int get_data(int *amount);
int dispenseBills(int amount,int *fifties,int *twenties,int *tens);
int printBills(int amount,int fifties,int twenties,int tens);

// main function
int main(void)
{
        // variable
        char tf;
        int amount, fifties, twenties, tens;
        int sentinal = 0;

        // sentinal loop
        while( sentinal == 0)
        {
                // necessary functions, i know i could have written less
                // to do this program
                get_data(&amount);
                dispenseBills( amount, &fifties, &twenties, &tens);
                printBills(amount, fifties, twenties, tens);

                // continue?
                printf("Do you want another transaction?");
                scanf(" %c", &tf);
                if(tf == 'n' || tf == 'N')
                {
                        sentinal = 1;
                }
                else if(tf == 'Y' || tf == 'y')
                {
                }
                else{
			int sentinal2 = 0;
			while(sentinal2==0)
			{
                        	printf("y/n :");
                        	scanf(" %c",&tf);
				if(tf=='n'||tf=='N'){
					return 0;
				}
				else if(tf=='y'||tf=='Y'){
					sentinal2=1;
				}
			}
                }
        }
        return 0;
}

// function that gets initial data
int get_data(int *amount)
{
        printf("Enter how much cash you need?");
        scanf("%d", &*amount);
        while(0 != *amount % 10)
        {
                printf("This machine dispenses ONLY $50, $20, and $10...\n");
                printf("Please enter again");
                scanf("%d",&*amount);
        }
        return 0;
}

// function that interprets data
int dispenseBills(int amount,int *fifties,int *twenties,int *tens)
{
        *fifties = amount / 50;
        amount = amount - (*fifties * 50);
        *twenties = amount / 20;
        amount = amount - (*twenties * 20);
        *tens = amount / 10;
        return 0;
}

// function that spews out the info
int printBills(int amount,int fifties, int twenties,int tens)
{
        printf("The amount you are withdrawing is $%d.\n", amount);
        printf("* * * Take your Cash as $$$ bills * * *\n");
        printf("%d fifties %d twenties %d tens\n\n",fifties, twenties, tens);
        return 0;
}


//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//
//        Name:             
//        Date:             11/15/2010
//        File Name:        bills.c
//
//        E-Mail:          
//
//        Assignment:       #5
//
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

/* This is a program for an ATM machine that dispenes money. The user should
   enter the amount desired in a multiple of ten, and the machine will dispense
   that amount in 50s, 20s and 10s                                       */

#include<stdio.h>

/* Function Prototypes */

void get_data(int *amount);
/* Gets the amount entered by the user
   pre - amount contains an address of a memory cell where the
         results are stored
   post - function stores the result in cell pointed to by amount */

void dispenseBills (int amount, int *fifties, int *twenties, int *tens);
/* Converts amount of money specified by user into appropriate bills
   pre - amount specified by user, includes addresses of cells 
         for fifties, twenties and tens
   post- function stores the results in cells pointed to by 
         fifties, twenties and tens  */

void printBills (int amount, int fifties, int twenties, int tens);
/* Function prints out to the user the amount of money they specified */

char SENTINEL = 'n';

int main(void)
{
       int amount;                    /* Imput- user enters amount they wish to take out    */
       int fifties, twenties, tens;  /* Output- Prints out amount in 10s, 20s and 50s      */
       char nextTransition;          /* Character entered by user to make more transitions */

       for (nextTransition = 'y'; nextTransition != SENTINEL; scanf("%c", &nextTransition)) {
               
                get_data(&amount); /* Function call for get_data */

                /* Function call for dispenseBills */
                dispenseBills(amount, &fifties, &twenties, &tens); 
               
                /* Function call for printBills */
                printBills(amount, fifties, twenties, tens);

                printf("Would you like to make another transaction? y/n >\n");
           }
         
        printf("End Transaction. Thank You.\n");

        return(0);

}

/* Function definition */
void get_data (int *amount)
{
       int test;
       printf("Please enter the amount you wish to withdraw $\n");
       scanf("%d", amount);

       test = *amount % 10;

       while (test != 0) {
             
             printf("This machine dispenses only $50, $20, $10...\n");
             printf("Please enter another amount $ \n");
             scanf("%d", amount);
             test = *amount % 10;
       }
}

void dispenseBills (int amount, int *fifties, int *twenties, int *tens)
{
        int change;

        if (amount >=50) {
             *fifties = (amount / 50);
             change = amount - (*fifties * 50);
             *twenties = (change / 20);
             change = amount - (*twenties * 20);
             *tens = change / 10; 
            }
        else if (amount < 50 && amount > 10)  {
                 *fifties = 0;
                 *twenties = (amount / 20);
                 change = amount - (*twenties * 20);
                 *tens = change / 10;
            }
        else if  (amount == 10) {
                 *fifties = 0;
                 *twenties = 0;
                 *tens = 1;
                }
}

void printBills (int amount, int fifties, int twenties, int tens)
{
       printf("The amount you are withdrawing = $%d\n", amount);
       printf("*** Take your Cash as $$$ bills ***\n");
       printf("%d fifties, %d twenties, %d tens\n", fifties, twenties, tens);
}

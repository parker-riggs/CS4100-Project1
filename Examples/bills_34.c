//*************************************************
//
//    
//
//    bills.c
//
//    11/14/10
//  
//  This program takes the total value entered
//   and determines how many 50 20 and 10
//   dollar bills is neccessary to give that amount
//**************************************************


#include <stdio.h>

void get_data(int *amount);

void dispensebills(int amount, int *fifties, int *twenties, int *tens);

void printbills(int amount, int fifties, int twenties, int tens);

int main(void)
{

   int total;
   int five;
   int two;
   int one;

   get_data(&total);

   dispensebills(total,&five,&two,&one);

   printbills(total, five, two, one);
   
   printf("value is not multiple of ten, please re-enter a value");
   total != total % 10;

 return(0);

}


void get_data(int *amount)
{

   printf("Enter the value (multiple of ten) > ");
   scanf("%d",amount);
   
   {
     printf("The value must be divisible by 10");
     scanf("%d",amount);
   }
}


void dispensebills(int amount, int *fifties, int *twenties, int *tens)
{
    int i;
   
    for(i = amount; i >= 1;){
    *fifties = i % 50;
    *twenties = *fifties % 20;   
    *tens = *twenties % 10;
    }
}  
     
void printbills(int amount, int fifties, int twenties, int tens)
{
  
  printf(" The total value is %d \n",amount);
  printf(" %d amount of $50 bills \n",fifties);
  printf(" %d amount of $20 bills \n",twenties);
  printf(" %d amount of $10 bills \n",tens);
}


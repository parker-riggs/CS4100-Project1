//........................................
// Name : 
// Date : 11/09/2010
// Program : Bill for an automatic teller machine
//..........................................
#include <stdio.h>
#include <math.h>

void get_data(int *amountp);
/*pre - num contains an address of the memory cell where the results are to be stored.
post - function stores the result in the cell pointe to by num */

void dispensebills(int amount,int *fifties, int *twentiesp, int *tensp);
/*dispense the amount in three parts
pre - num is defind fiftiesp,twentiesp and tensp contain an addresses of a locations
post - result are stored in cell pointed to by fiftiesp,twentiesp and tensp */

void printbills(int amount,int fifties,int twenties ,int tens);
/*print the result - the original amount,the fifties part,the twenties parts and 
 the tens part */
int main(void)
{

                
                 int amount;          /*input -  The amount you are withdrawing */
                 int bill_50;         /* fifties bills output amount*/
                  int bill_20;        /* twenties bills output amount*/
                   int bill_10;       /* tens bills output amount*/             
                    char ans = 'Y';    /* the user response */
                       
                 while (ans == 'Y' || ans == 'y'){
                          get_data(&amount);
                          dispensebills(amount, &bill_50, &bill_20, &bill_10);
                          printbills(amount,bill_50,bill_20 ,bill_10);
                          printf("Do you want another transaction (n/y)? ");
                          scanf(" %c",&ans);
			 // printf("%c", ans);
                 
                 }
              
                return(0);
}
void get_data(int *amountp)
{                 int remainder; 
                  int cash;
               
               
                  printf("Eneter how much cash that you need\n");
                  scanf("%d",&cash);
                  remainder = cash % 10;
               while (remainder % 10  != 0)
                  {
                  printf("This machine dispences ONLY $50,$20,10...\n");
                  printf("please enter again\n");
                  scanf("%d",&cash);
                  remainder = cash % 10;
                  }
                  *amountp = cash;     
}
              
void dispensebills(int amount,int *fiftiesp, int *twentiesp, int *tensp){
             int fifty = 0,
                  twenty = 0,   
                   tens = 0;

                  while (amount > 0){

                  if (amount >= 50) {
                       amount -= 50;
                       fifty +=1;    
                        }
                     else if (amount >=20){
                         amount -= 20;
                         twenty += 1;
                        }
                        else{
                            amount -= 10;
                            tens +=1;
                            }
                     }                 
                 
               *fiftiesp  = fifty;  
               *twentiesp =  twenty;
               *tensp     = tens;
                
 }                

void printbills(int amount,int fifties,int twenties ,int tens)
                 {
                  printf("The amount you are withdrawing =$%d\n",amount);
                  printf("***Take your cash as $$$ bill***\n");
                  printf("%d fifties %d twenties %d tens \n\n\n",fifties,twenties,tens);
                  
                 }

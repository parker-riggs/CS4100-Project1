// * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//  name: 
//  date: 11/15/10
//  program: bills.c
//
//  description: this program asks the reader for
//        an input of desired money in certain intervals
//        and outputs what the reader recieves
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
#include <stdio.h>
                 
void get_data(int *num);
        /*Pre - num contains address of memory cell where the results are 
        Post - function stores the result in cell that is pointed to 
        */      
        
void dispenseBills (int total, int *fifty, int *twenty, int *ten);
        /*Pre - total is defined where fifty, twenty and ten and address location is
        Post - Results are stored in the locations that are pointed to by fifty
        */  
                 
void printBills(int tot, int fifty, int twenty, int ten);
        /* Prints result - the amount, number of fifties, twenties, and tens
        */   
int main(void)  
{       
         
    int amount,
        fifties,
        twenties,
        tens;
                
        char ans = 'Y';
                
        while ( ans == 'Y' || ans =='y')
        {
                get_data(&amount);
        
                dispenseBills(amount, &fifties, &twenties, &tens);
                 
                printBills(amount, fifties, twenties, tens);
        
                printf("Do you want another transaction (y/n)?: ");
                scanf(" %c", &ans);
                               
          }
        
                
        return (0);
}       

void get_data(int *num)
{               
        int val;
                
        printf("Enter how much cash do you need?: ");
        scanf("%d", &val);
                
        while (val%10 != 0)
        {
                printf("This machine dispenses ONLY $50, $20, $10..\n");
                
		printf("Please enter again: ");
                scanf("%d", &val);
        }
                
        *num = val;
}       
                
void dispenseBills (int num, int *fifty, int *twenty, int *ten)
{       
        int five,
            two,
            one;
         
        five = num / 50;
        num = num - (five * 50);
        
	two = num / 20;
        num = num - (two *20);
        
	one = num / 10; 
        
        *fifty = five;
        *twenty = two;
        *ten = one;
}        

void printBills(int num, int fifty, int twenty, int ten)
{       
        printf("The amount you are withdrawing = %d\n", num);
        
	printf("*** Take your Cash as $$$ Bills ***\n");
        
	printf("%d fifties, %d twenties and %d tens\n", fifty, twenty, ten);
}       
        
        

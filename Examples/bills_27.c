//****************************************************************************
//Program: Bills.c
//Name: 
//Email:
//Description: Operations of an ATM machine 
//Date: November 15, 2010
//****************************************************************************

#include<stdio.h> /*header files...*/
#include<math.h>

int get_data(int cash);

int main(void) {
int cash, /*declares ints*/
	answer,
	y, n,
	output,
	iter,
	mon,
	ans,
	remainder,
	f,
	t,
	te;

do{    /* prompts it to ask for another transaction*/
		printf("\nHow much cash would you like to withdraw?");
		scanf("%d",&cash);
		ans = cash % 10;
		while(ans!=0){
			printf("Error: Transaction must be multiple of 10, try again.\n");  
			printf("How much cash would you like to withdraw?");
			scanf("%d",&cash);
			ans = cash % 10;
		}

	if(cash == 10){
		printf("0 fifties, 0 twenties and 1 ten\n");
	}else if(cash == 20){
		printf("0 fifties, 1 twenty and 0 tens\n");	
	}else if(cash == 30){
		printf("0 fifties, 1 twenty and 1 ten\n");
	}else if(cash == 40){
		printf("0 fifties, 2 twenties and 0 tens\n");
	}else if(cash == 50){
		printf("1 fifty, 0 twenties and 0 tens\n");
	} else {
		printf("Due to security reasons no more then $50 can be taken from this ATM per transaction\n"); /*fail*/
    }
printf("Would you like another transaction? (y/n): "); /*tries to prompt another transaction*/
scanf("%d", &answer);
}while(answer = y);

return(0);
}
		
/*sorry that this program is so bad, I got stuck in the math of all this and ran out of time.
this is the most accurate program I could do without having it go into an inf. loop or not work at all.*/
    
    
    
    
    
  


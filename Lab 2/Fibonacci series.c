#include<stdio.h> 
#include<stdio.h>
int main()    {    
int temp1 = 0, temp2 = 1, nextTerm=0;
int num = 0 ;
printf("Enter the Fibonacci number:");    
scanf("%d",&num); 
  if(num == 0)
    printf("%d",0);
  for (int i = 2; i <= num; i++){
    printf("%d ",nextTerm);
    temp1 = temp2;
    temp2 = nextTerm;
    nextTerm = temp1 + temp2;
  }
}    
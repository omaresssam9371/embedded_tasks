#include<stdio.h>    
int main()    
{    
 int time,min,hour,sec = 0;
     
 printf("Enter the total time elapsed in seconds:");    
 scanf("%i",&time );    

 hour = time / 3600;
 min = (time%3600) / 60;
 sec = (time%3600) %60;
 printf("%i:%i:%i",hour,min,sec);    

  return 0;  
 }    
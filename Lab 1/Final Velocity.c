#include<stdio.h>    
int main()    
{    
 float u,v,a,t,s = 0;
     
 printf("Enter the the initial velocity ,acceleration and time:");    
 scanf("%f %f %f",&u ,&a,&t);    

v = u + a*t;
s = u*t + 0.5*a*t*t;
 
printf("the final velocity %0.2f and distance traversed %0.2f",v,s );    

  return 0;  
 }    
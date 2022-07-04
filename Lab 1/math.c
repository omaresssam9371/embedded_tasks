#include<stdio.h>    
int main()    
{    
 float num1,num2,num3,sum,avg,product = 0;
     
printf("Enter the three different inputs integers:");    
scanf("%f %f %f",&num1 ,&num2,&num3); 

sum = num1 +num2 +num3;
printf("Sum is %0.2f \n",sum);    

printf("Average is %0.2f \n",sum/3);    

product = num1*num2*num3;
printf("Product is %0.2f \n",product);    

printf("smallest=%0.2f\n",(num1<num2&&num1<num3)?num1:(num2<num1&&num2<num3)?num2:num3);
printf("Longest=%0.2f\n",(num1>num2&&num1>num3)?num1:(num2>num1&&num2>num3)?num2:num3);

return 0;  

}    
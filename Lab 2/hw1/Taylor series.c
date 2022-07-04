#include<stdio.h> 
int main()    {    
    float x, itr_num = 0.0f;
    int i = 1;
    float result = 1.0f;
    printf("Enter the exponent and the number of iteration:");    
    scanf("%f %f",&x ,&itr_num);
    for (i = itr_num - 1, result = 1; i > 0; --i )
        result = 1 + x * result / i; 
    printf("exponential result : %0.5f",result);
}    
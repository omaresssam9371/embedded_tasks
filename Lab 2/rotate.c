#include<stdio.h> 
#include<stdio.h>
int main()    {   
    unsigned char x;
    unsigned char result;
    int n,o = 0 ;
    printf("Enter an 8 bit number ,number of rotate cycles and rotate option:");    
    scanf("%d %d %d",&x,&n,&o); 
        if(n>=8) n = n%8;
        //1 for right rotation
        if(o == 1){
            result =(x >> n) |(x << (8 - n));
            printf("%d after %d rotations: %d",x,n,result);
        }//0 for left rotation
        else if(o == 0){
            result =(x << n) |(x >> (8 - n));
            printf("%d after %d rotations: %d",x,n,result);
        }
}    
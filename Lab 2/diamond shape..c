#include<stdio.h>    
int main()    
{   int n = 9;
    int sp1,sp2 = 4;
    int st = 1;
    //iterate until we make the 9 lines
    while(n--){
        //left spaces
       for(int i = 0; i < sp1; i++)
            printf(" ");
        //middle stars
        for(int j = 0; j < st; j++)
            printf("*");
        //right spaces
        for(int k = 0; k < sp2; k++)
            printf(" ");
        //above pyramid
        if(n >= 5){
            sp1 --;
            sp2 --;
            st = st + 2;
        }
        //upside down pyramid
        if(n < 5){
            sp1 ++;
            sp2 ++;
            st = st - 2;
        }
        printf("\n");
    }
    
}    
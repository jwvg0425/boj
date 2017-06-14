#include<stdio.h>
 
int main()
{
    int input;
    int i;
    int j;
 
    //별 개수=1+2*i개
    //공백 개수=input-1-i개
 
    scanf("%d",&input);
 
    for(i=0;i<input;i++)
    {
        for(j=0;j<input-1-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<1+2*i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    input-=1;
    for(i=input;i>0;i--)
    {
        for(j=0;j<input-i+1;j++)
        {
            printf(" ");
        }
        for(j=0;j<2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
 
int min(int a,int b)
{
    return (a<b)? a:b;
}
 
int getGCD(int a,int b)
{
    int i=min(a,b);
    for(i;i>0;i--)
    {
        if(a%i==0 && b%i==0)
        {
            return i;
        }
    }
}
 
int getLCM(int a,int b)
{
    int GCD=getGCD(a,b);
    return GCD*a/GCD*b/GCD;
}
 
int main()
{
    int input1,input2;
 
    scanf("%d %d",&input1,&input2);
    printf("%d %d",getGCD(input1,input2),getLCM(input1,input2));
    return 0;
}
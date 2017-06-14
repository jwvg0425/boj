#include<stdio.h>
int x[1000001]={0};
int main(void)
{
    long long I,i,k,a,b,s=0;
    scanf("%lld%lld",&a,&b);
    for(i=2;i*i<=b;i++)
    {
        I=i*i;
        k=a/I;
        if(I*k<a)
            k++;
        for(;I*k<=b;k++)
            x[I*k-a]=1;
    }
    for(i=0;i<=b-a;i++)
        s+=!x[i];
    printf("%lld",s);
}
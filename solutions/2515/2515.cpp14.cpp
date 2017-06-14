#include<stdio.h>
#include<stdlib.h>
 
int N,S,cost[300000],next[300000],m[300001];
struct picture
{
    int h,c;
};
picture pic[300000];
int max(int a,int b){return (a>b)?a:b;}
int compare(const void* a,const void* b)
{
    return ((picture*)a)->h-((picture*)b)->h;
}
int show(int selected)
{
    if(cost[selected]!=0)return cost[selected];
    if(pic[selected].h+S>pic[N-1].h)return pic[selected].c;
 
    int& ret = cost[selected];
    int i;
 
    ret=m[next[selected]]+pic[selected].c;
    return ret;
}
 
int main()
{
    int i,j=0;
 
    scanf("%d %d",&N,&S);
 
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&pic[i].h,&pic[i].c);
    }
    qsort(pic,N,sizeof(picture),compare);
    for(i=0;i<N;i++)
    {
        for(;(pic[j].h<pic[i].h+S)&&j<N;j++);
        next[i]=j;
    }
    for(i=N-1;i>=0;i--)
    {
        m[i]=max(m[i+1],show(i));
    }
    printf("%d",m[0]);
 
}
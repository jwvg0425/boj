#include<stdio.h>
#include<stdlib.h>
 
int N,people[100001],arr[400001],s[100001];
 
int compare(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}
int init(int start,int end,int node)
{
    if(start==end)return arr[node]=1;
    int mid=(start+end)/2;
    arr[node]=end-start+1;
    return init(start,mid,node*2)+init(mid+1,end,node*2+1);
}
int renew(int node)
{
    if(node==0) return 0;
    arr[node]-=1;
    return renew(node/2);
}
 
int search(int key,int start,int end,int node)
{
    if(key==arr[node]&&start==end)
    {
        renew(node);
        return end;
    }
    int mid=(start+end)/2;
    if(key<=arr[node*2])return search(key,start,mid,node*2);
    return search(key-arr[node*2],mid+1,end,node*2+1);
     
}
int main()
{
    int i,j;
 
    scanf("%d",&N);
    for(i=1;i<=N;i++)
        scanf("%d",&people[i]);
    for(i=1;i<=N;i++)
        scanf("%d",&s[i]);
    qsort(people,N+1,sizeof(int),compare);
    init(1,N,1);
    for(i=N;i>0;i--)
    {
        j=search(s[i]+1,1,N,1);
        s[i]=people[j];
    }
    for(i=1;i<=N;i++)
        printf("%d\n",s[i]);
}
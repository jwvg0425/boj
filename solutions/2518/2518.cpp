#include<stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
 
int N,order[3][101],cache[101][101][101][3];
 
int minTurn(int a,int b)
{
    return (a>b)?min(a-b,b+N-a):min(b-a,a+N-b);
}
 
int eat(int a,int b,int c,int i)
{
    if(a==order[0][0]&&b==order[1][0]&&c==order[2][0])return 0;
    if(cache[a][b][c][i]!=0)return cache[a][b][c][i];
 
    int& ret = cache[a][b][c][i];
    int now;
    ret=0x7FFFFFFF;
 
    switch(i)
    {
    case 0:now=order[i][a];break;
    case 1:now=order[i][b];break;
    case 2:now=order[i][c];break;
    }
    if(a<order[0][0])
        ret=min(ret,eat(a+1,b,c,0)+minTurn(now,order[0][a+1]));
    if(b<order[1][0])
        ret=min(ret,eat(a,b+1,c,1)+minTurn(now,order[1][b+1]));
    if(c<order[2][0])
        ret=min(ret,eat(a,b,c+1,2)+minTurn(now,order[2][c+1]));
    return ret;
}
 
int main()
{
    int i,j,m;
 
    scanf("%d",&N);
 
    for(i=0;i<3;i++)
    {
        scanf("%d",&order[i][0]);
        for(j=1;j<=order[i][0];j++)
        {
            scanf("%d",&order[i][j]);
            switch(i)
            {
            case 1:order[i][j]=(order[i][j]+N/3*2)%N;break;
            case 2:order[i][j]=(order[i][j]+N/3)%N;break;
            }
        }
    }
    m=eat(1,0,0,0)+minTurn(1,order[0][1]);
    m=min(m,eat(0,1,0,1)+minTurn(1,order[1][1]));
    m=min(m,eat(0,0,1,2)+minTurn(1,order[2][1]));
    printf("%d",m);
}
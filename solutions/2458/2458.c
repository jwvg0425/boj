g[501][501],t[501][501],i,j,n,m,a,b,c,o;
h(a,b)
{
    int k;
     
    if(t[a][b]==1)
        return;
    t[a][b]=1;
    for(k=1;k<=n;k++)
    {
        if(g[b][k]==1)
            h(a,k);
    }
}
s(a,b)
{
    int k;
     
    if(t[a][b]==2)
        return;
    t[a][b]=2;
    for(k=1;k<=n;k++)
    {
        if(g[b][k]==-1)
            s(a,k);
    }
}
 
main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        g[a][b]=1;
        g[b][a]=-1;
    }
    for(i=1;i<=n;i++)
    {
        h(i,i);
        s(i,i);
        for(j=1,c=0;j<=n;j++)
        {
            c+=(t[i][j]!=0);
        }
        if(c==n)
            o++;
    }
    printf("%d",o);
}
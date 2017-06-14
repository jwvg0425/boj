a[101][101],n,s,i,j,k,c[101],m;
d(b)
{
    int t;
    c[b]=1;
    for(t=1;t<=n;t++)
    {
        if(a[b][t]==1&&c[t]==0)
            d(t);
    }
}
main()
{
    scanf("%d %d",&n,&s);
    for(i=0;i<s;i++)
    {
        scanf("%d %d",&j,&k);
        a[j][k]=1;
        a[k][j]=1;
    }
    d(1);
    for(i=2;i<=n;i++)
        m+=c[i];
    printf("%d",m);
}
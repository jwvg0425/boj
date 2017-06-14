s[101],e[101],d[501][501],i,j,n;
 
m(a,b)
{
    int i;
 
    for(i=1;i<=n;i++)
    {
        if(s[i]==a&&e[i]==b)
            return 1;
    }
    return 0;
}
M(a,b){return a>b?a:b;}
 
main()
{
    scanf("%d",&n);
 
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&s[i],&e[i]);
    }
 
    for(i=1;i<=500;i++)
    {
        for(j=1;j<=500;j++)
        {
            d[i][j]=M(d[i-1][j-1]+m(i,j),M(d[i-1][j],d[i][j-1]));
        }
    }
    printf("%d",n-d[500][500]);
}
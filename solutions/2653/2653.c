a[100][100],b[100],i,j,n,t,s;
 
main()
{
    for(scanf("%d",&n);i<n;i++)
    {
        for(t=0,j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            t+=a[i][j];
            if(t==n-1)
            {
                printf("0");
                return;
            }
        }
    }
 
    for(i=0;i<n;i++)
    {
        if(b[i]==1)
            continue;
 
        for(j=i;j<n;j++)
        {
            if(a[i][j]==0)
                b[j]=1;
        }
        s++;
    }
 
    printf("%d\n",s);
 
    for(i=0;i<n;i++)
    {
        if(b[i]==0)
            continue;
 
        for(j=i;j<n;j++)
        {
            if(a[i][j]==0)
            {
                printf("%d ",j+1);
                b[j]=0;
            }
        }
        printf("\n");
    }
}
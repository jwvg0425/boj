n,a[3][101],i,j,s=100,k=100,t=100;
 
main()
{
    scanf("%d",&n);
 
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a[0][i],&a[1][i],&a[2][i]);
    }
 
    for(i=0;i<n;i++)
    {
        if(a[2][s]<a[2][i]) s=i;
    }
    printf("%d %d\n",a[0][s],a[1][s]);
 
    a[2][s]=-1;
 
    for(i=0;i<n;i++)
    {
        if(a[2][k]<a[2][i])k=i;
    }
    printf("%d %d\n",a[0][k],a[1][k]);
    a[2][k]=-1;
    if(a[0][s]==a[0][k])k=-1;
     
 
    for(i=0;i<n;i++)
    {
        if(k==-1&&a[0][i]==a[0][s])
            continue;
 
        if(a[2][t]<a[2][i])t=i;
    }
    printf("%d %d",a[0][t],a[1][t]);
}
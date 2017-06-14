a[20001],n,i,j,c,k=1,b,t;
g(a,b)
{
    int t;
    if(b>a)
    {
        t=a;
        a=b;
        b=t;
    }
    if(a%b==0)
        return b;
 
    return g(b,a%b);
}
main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
 
    for(i=1;i<=n;i++)
    {
        if(a[i]==-1)
            continue;
        j=i;
        do
        {
            t=j;
            j=a[j];
            c++;
            a[t]=-1;
        }while(j!=i);
        b=g(k,c);
        k=k/b*c;
        c=0;
    }
    printf("%d",k);
}
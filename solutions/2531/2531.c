n,d,k,c,a[3000001],b[3001],i,j,s=1,m;
main()
{
    scanf("%d %d %d %d",&n,&d,&k,&c);
    b[c]++;
 
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
 
        if(i<k)
        {
            if(b[a[i]]==0) s++;
            b[a[i]]++;
 
             
        }
        else
        {
            b[a[i-k]]--;
            if(b[a[i-k]]==0)
                s--;
 
            if(b[a[i]]==0)s++;
            b[a[i]]++;
        }
        if(s>m)m=s;
    }
 
    for(i=n;i<n+k;i++)
    {
        b[a[i-k]]--;
        if(b[a[i-k]]==0)
            s--;
        if(b[a[i%n]]==0)s++;
        b[a[i%n]]++;
        if(s>m)m=s;
    }
    printf("%d",m);
}
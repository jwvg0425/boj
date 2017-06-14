long long int a[999],b[999],n,i,j,t,l,m;
main()
{
    scanf("%lld",&n);
     
    for(i=0;n;i++,n/=2)
    {
        a[i]=n%2;
        b[i]=n%2;
    }
     
    for(i=0,t=0;i<999;a[i]=0,i++)
    {
        if(a[i]==1)
        {
            if(a[i+1]==0)
            {
                a[i+1]=1;
                a[i]=0;
                for(j=0;j<=i;j++)
                {
                    if(j<t)
                        a[j]=1;
                    else
                        a[j]=0;
                }
                break;
            }
            t++;
        }
    }
     
    for(n=1,i=0;i<999;i++,n*=2)
        l+=a[i]*n;
         
    for(i=0,t=0;i<999;b[i]=0,i++)
    {
        if(b[i]==0)
        {
            if(b[i+1]==1)
            {
                b[i]=1;
                b[i+1]=0;
                for(j=0;j<i;j++)
                {
                    if(j<i-t)
                        b[j]=0;
                    else
                        b[j]=1;
                }
                break;
            }
        }
        if(b[i]==1)
            t++;
    }
     
    for(n=1,i=0;i<999;i++,n*=2)
        m+=b[i]*n;
         
    printf("%lld %lld",m,l);
}
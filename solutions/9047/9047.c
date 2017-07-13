a,b,c,d,i,n,t;
 
main()
{
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
 
    for(i=0;n!=6174;i++)
    {
        a=n/1000;
        b=n/100%10;
        c=n/10%10;
        d=n%10;
        if(b>a){n=a;a=b;b=n;}
        if(c>a){n=a;a=c;c=n;}
        if(d>a){n=a;a=d;d=n;}
        if(c>b){n=b;b=c;c=n;}
        if(d>b){n=b;b=d;d=n;}
        if(d>c){n=c;c=d;d=n;}
 
        n=(a-d)*999+(b-c)*90;
    }
 
    printf("%d\n",i);
    }
}
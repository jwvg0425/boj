char s[1001];d,t,u,i;
main()
{
    for(;;)
    {
        scanf("%s",s);
        if(s[0]==48)
            return;
        d=0;
        for(i=0;i<strlen(s);i++)
        {
            d+=s[i]-48;
        }
        t=d;
        while(t>=10)
        {
            for(i=10;t;t/=i)
            {
                u+=t%i;
            }
            t=u;
            u=0;
        }
        printf("%d\n",t);
    }
}
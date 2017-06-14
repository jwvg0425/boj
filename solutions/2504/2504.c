char a[31];c,n,m;
k(t)
{
    int x,s=0;
    for(;a[c]!=t;)
    {
        if(c>=strlen(a))
        {
            return -1;
        }
        c++;
        switch(a[c-1])
        {
        case '(':
            x=k(')');
            break;
        case '[':
            x=k(']');
            break;
        default:
            return -1;
        }
        if(x==-1)
            return -1;
        s+=x;
    }
    c++;
    switch(t)
    {
    case ')':
        if(s==0)
            return 2;
        else
            return 2*s;
    case ']':
        if(s==0)
            return 3;
        else
            return 3*s;
    }
}
main()
{
    scanf("%s",a);
    for(;c<strlen(a);)
    {
        c++;
        switch(a[c-1])
        {
        case '(':
            m=k(')');
            break;
        case '[':
            m=k(']');
            break;
        default:
            printf("0");
            return;
        }
        if(m==-1)
        {
            printf("0");
            return;
        }
        n+=m;
    }
    printf("%d",n);
}
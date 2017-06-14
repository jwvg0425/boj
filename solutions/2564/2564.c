w,h,N;i,j,t;s;
struct
{
    int a;int b;
}a[100],b;
 
main()
{
    scanf("%d %d %d",&w,&h,&N);
 
    for(i=0;i<N;i++)
    {
        scanf("%d %d",&a[i].a,&a[i].b);
    }
    scanf("%d %d",&b.a,&b.b);
 
    for(i=0;i<N;i++)
    {
        switch(a[i].a)
        {
        case 1:
            switch(b.a)
            {
            case 1:
                s+=abs(b.b-a[i].b);
                break;
            case 2:
                j=a[i].b+b.b+h;
                t=2*w-a[i].b-b.b+h;
                s+=j>t?t:j;
                break;
            case 3:
                s+=a[i].b+b.b;
                break;
            case 4:
                s+=b.b+w-a[i].b;
                break;
            }
            break;
        case 2:
            switch(b.a)
            {
            case 1:
                j=a[i].b+b.b+h;
                t=2*w-a[i].b-b.b+h;
                s+=j>t?t:j;
                break;
            case 2:
                s+=abs(b.b-a[i].b);
                break;
            case 3:
                s+=a[i].b+h-b.b;
                break;
            case 4:
                s+=w+h-a[i].b-b.b;
                break;
            }
            break;
        case 3:
            switch(b.a)
            {
            case 1:
                s+=a[i].b+b.b;
                break;
            case 2:
                s+=b.b+h-a[i].b;
                break;
            case 3:
                s+=abs(b.b-a[i].b);
                break;
            case 4:
                j=a[i].b+b.b+w;
                t=2*h-a[i].b-b.b+w;
                s+=j>t?t:j;
                break;
            }
            break;
        case 4:
            switch(b.a)
            {
            case 1:
                s+=a[i].b+w-b.b;
                break;
            case 2:
                s+=w+h-a[i].b-b.b;
                break;
            case 3:
                j=a[i].b+b.b+w;
                t=2*h-a[i].b-b.b+w;
                s+=j>t?t:j;
                break;
            case 4:
                s+=abs(b.b-a[i].b);
                break;
            }
            break;
        }
    }
    printf("%d",s);
}
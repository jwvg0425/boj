a[21],n=1,i,s=-1;
main(k)
{
    scanf("%d",&k);
    for(;;n*=2,i++)
    {
        a[i]=k%2;
        if(s==-1&&a[i]==1)
            s=i;
        k/=2;
        if(!k)
            break;
    }
    printf("%d %d",i-s?n*2:n,i-s?i-s+1:0);
}
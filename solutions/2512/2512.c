#include<stdio.h>
 int n,a[10001],i,j,k,m,s,t;
 
int main() { scanf("%d",&n);
 
for(i=0;i<n;i++) { scanf("%d",a+i); if(a[i]>t) t=a[i]; s+=a[i]; for(j=0;j<n;j++) { if(a[i]>a[j]) { for(k=i;k>=j;k--) { a[k+1]=a[k]; } a[j]=a[i+1]; } } }
 
scanf("%d",&m);
 
if(s<=m) { printf("%d",t); return 0; }
 
a[n]=0; for(i=1;i<=n;i++) { s-=a[i-1]*i; s+=a[i]*i; if(s<=m) { s-=a[i]*i; for(j=a[i-1];j;j--) { if(s+j*i<=m) { printf("%d",j); return 0; } } } } }
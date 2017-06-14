#include<stdio.h>
#include<set>
 
 
int main()
{
    std::multiset<long long int> q;
    long long int N, c = 0;
 
    scanf("%lld", &N);
 
    for (int i = 0; i < N; i++)
    {
        long long int r;
        scanf("%lld", &r);
 
        q.insert(r);
    }
 
    while (q.size() > 1)
    {
        long long int a = *q.begin();
        long long int b = *(++q.begin());
        long long int n = a + b;
 
        c += a + b;
 
        q.erase(q.begin());
        q.erase(q.begin());
        q.insert(n);
    }
 
    printf("%lld", c);
}
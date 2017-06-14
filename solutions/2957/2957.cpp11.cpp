#include <stdio.h>
#include <algorithm>
#include <map>
#include <chrono>
#include <random>

std::map<int, int> indices;

int main()
{
    int N;
    scanf("%d", &N);
    
    long long sum = 0;
    
    for(int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        
        auto after = indices.lower_bound(k);
    
        if(after == indices.end() && indices.size() == 0) // root
        {
            indices[k] = 0;
        }
        else if(after == indices.end())
        {
            auto prev = indices.rbegin();
            int h = prev->second + 1;
            
            sum+=h;
            indices[k] = h;
        }
        else
        {
            auto now = after;
            auto prev = --after;
            
            int h = std::max(now->second, prev->second) + 1;
            
            sum+=h;
            indices[k] = h;
        }
        printf("%lld\n", sum);
    }
}




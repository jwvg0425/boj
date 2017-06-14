#include <stdio.h>
#include <vector>
#include <algorithm>
 
std::vector<int> cycleSize;
std::vector<int> edges;
std::vector<int> visited;
std::vector<bool> sizeCheck;
int N;
 
bool isPrime(int n)
{
    if (n == 1)
        return false;
 
    if (n == 2)
        return true;
 
    if (n % 2 == 0)
        return false;
 
    for (int i = 3; i*i <= n; i+= 2)
    {
        if (n%i == 0)
            return false;
    }
 
    return true;
}
 
void dfs(int n)
{
    if (visited[n] != 2)
        visited[n] = 1;
 
    int goal = edges[n];
 
    //목적지가 이미 싸이클 판단됨
    if (visited[goal] == 2)
    {
        visited[n] = 2;
        return;
    }
 
    //한 번도 간 적 없는 경우 방문 표시해주고 거기서 dfs go go
    if (visited[goal] == 0)
    {
        dfs(goal);
        visited[n] = 2;
        return;
    }
 
    // 방문한 적 있는데 cycle 아니다 -> 이 놈은 cycle 구성 요소.
    if (visited[goal] == 1)
    {
        int length = 1;
 
        while (goal != n)
        {
            length++;
 
            visited[goal] = 2;
            goal = edges[goal];
        }
        visited[n] = 2;
 
        if (!sizeCheck[length])
        {
            cycleSize.push_back(length);
            sizeCheck[length] = true;
        }
 
        return;
    }
 
}
 
int main()
{
    scanf("%d", &N);
 
    edges.push_back(-1);
    edges.reserve(N + 1);
    visited.resize(N + 1, false);
    sizeCheck.resize(N + 1, false);
     
    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        edges.push_back(t);
    }
 
    //get cycle size - O(N)
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }
 
    std::sort(cycleSize.begin(), cycleSize.end());
    auto last = std::unique(cycleSize.begin(), cycleSize.end());
 
    cycleSize.erase(last, cycleSize.end());
 
 
    for (int i = 2; i <= 2*N; i++)
    {
        bool isOk = true;
        for (auto& size : cycleSize)
        {
            if (i % size == 0)
            {
                isOk = false;
                break;
            }
        }
 
        if (isOk)
        {
            printf("%d", i);
            return 0;
        }
    }
 
    /*
    int maxCycle = *std::max_element(cycleSize.begin(), cycleSize.end());
 
    for (int i = maxCycle + 1; i <= 2*1000000000; i++)
    {
        if (isPrime(i))
        {
            printf("%d", i);
            return 0;
        }
    }*/
 
    printf("-1");
 
    return 0;
}
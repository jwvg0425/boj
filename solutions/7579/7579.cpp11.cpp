#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

std::vector<int> cost;
std::vector<int> memory;
int N, M;


//table[n][c] = n번째부터 cost c 만큼 쓸 때 확보가능한 최대 memory값
int table[101][10001];

int maxMemory(int n, int c)
{
	if (n == N)
		return 0;

	if (c < 0)
		return 0;

	int& res = table[n][c];

	if (res != 0)
		return res;

	res = std::max(0, maxMemory(n + 1, c));

	if (c >= cost[n])
		res = std::max(res, memory[n] + maxMemory(n + 1, c - cost[n]));

	return res;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		int m;
		scanf("%d", &m);
		memory.push_back(m);
	}

	int maxCost = 0;

	for (int i = 0; i < N; i++)
	{
		int c;
		scanf("%d", &c);
		cost.push_back(c);
		maxCost += c;
	}

	for (int c = 0; c <= maxCost; c++)
	{
		if (maxMemory(0, c) >= M)
		{
			printf("%d", c);
			return 0;
		}
	}
}
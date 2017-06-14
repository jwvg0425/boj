#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

int N, M, K;

std::vector<std::pair<int, int>> edge[300];
int table[301][301];

//n번째 위치에서 m개 이하 거쳐서 갈 때 최댓값
//항로가 없으면 -987654321 리턴
int answer(int n, int m)
{
	int& res = table[n][m];
	
	if (res != -1)
		return res;

	//도착
	if (n == N)
		return 0;

	//n번째 아닌데 더 이상 거쳐갈 길이 없음
	if (m == 0)
		return -987654321;

	res = -987654321;

	for (auto& e : edge[n])
	{
		res = std::max(res, e.second + answer(e.first, m - 1));
	}

	return res;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a < b)
			edge[a].emplace_back(b, c);
	}

	memset(table, -1, sizeof(table));

	printf("%d\n", answer(1, M - 1));

	return 0;
}
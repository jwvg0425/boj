#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <tuple>
#include <memory.h>

using ii = std::pair<int, int>;
//(xi, yi) - xi층에서 시작해서 yi층 간격으로 멈춤
std::vector<ii> elevators;

//각 층별로, 해당 층에 멈춰서는 엘리베이터 인덱스
std::vector<int> floors[100001];

//prev - 이전에 있었던 층, used - 거기서 탄 엘리베이터
int prev[100001];
int used[100001];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int xi, yi;
		scanf("%d %d", &xi, &yi);

		elevators.emplace_back(xi, yi);

		for (int f = xi; f <= n; f += yi)
		{
			floors[f].push_back(i);
		}
	}

	int a, b;
	scanf("%d %d", &a, &b);

	std::queue<int> q;

	prev[a] = -1;
	q.push(a);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		//현재 층에서 탈 수 있는 엘리베이터들 검사
		for (auto& idx : floors[now])
		{
			int xi, yi;

			std::tie(xi, yi) = elevators[idx];

			for (int f = xi; f <= n; f += yi)
			{
				if (prev[f] != 0)
					continue;

				prev[f] = now;
				used[f] = idx + 1;
				q.push(f);
			}
		}
	}

	//b로 도달하는 길이 없음
	if (prev[b] == 0)
	{
		printf("-1");
		return 0;
	}

	int distance = 0;
	std::vector<int> path;
	int trace = b;

	while (prev[trace] != -1)
	{
		path.push_back(used[trace]);

		trace = prev[trace];
		distance++;
	}

	std::reverse(path.begin(), path.end());

	printf("%d\n", distance);

	for (auto& p : path)
		printf("%d\n", p);

	return 0;
}
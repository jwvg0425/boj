#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>
#define MAX 987654321


int n, k, t, m;

struct Team
{
	int score[101] = { 0, };
	int submit = 0;
	int time = 0;

	void update(int t, int k, int s)
	{
		time = t;
		submit++;
		score[k] = std::max(score[k], s);
	}

	int totalScore() const
	{
		int total = 0;
		for (int i = 1; i <= k; i++)
		{
			total += score[i];
		}

		return total;
	}

	bool operator<(const Team& rhs)
	{
		int rtotal = rhs.totalScore();
		int ltotal = totalScore();

		if (ltotal < rtotal)
			return true;

		if (ltotal > rtotal)
			return false;

		if (submit > rhs.submit)
			return true;

		if (submit < rhs.submit)
			return false;

		if (time > rhs.time)
			return true;

		return false;
	}
};

void solve()
{
	Team teams[101];

	scanf("%d %d %d %d", &n, &k, &t, &m);

	for (int i = 1; i <= m; i++)
	{
		int id, j, s;
		scanf("%d %d %d", &id, &j, &s);

		teams[id].update(i, j, s);
	}

	int rank = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i == t)
			continue;

		if (teams[t] < teams[i])
			rank++;
	}

	printf("%d\n", rank);
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}
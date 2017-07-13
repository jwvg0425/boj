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
#include <time.h>

using ii = std::pair<int, int>;
std::vector<ii> papers;
int table[101];

//현재 맨 위에 놓인 색종이가 top번째 색종이일 때 그 위에 더 쌓을 수 있는 최대 개수
int solve(int top)
{
	if (top == papers.size())
		return 0;

	if (table[top] != -1)
		return table[top];

	int& res = table[top];
	res = 1;

	for (int i = 0; i < papers.size(); i++)
	{
		if (i == top)
			continue;

		if ((papers[top].first >= papers[i].first &&
			papers[top].second >= papers[i].second) ||
			(papers[top].first >= papers[i].second &&
			papers[top].second >= papers[i].first))
		{
			res = std::max(res, 1 + solve(i));
		}
	}
	return res;
}

int main()
{
	int n;

	//0번째거 모두 포용가능한 제일 큰걸로 올려둔다
	papers.emplace_back(1000, 1000);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		papers.emplace_back(a, b);
	}

	memset(table, -1, sizeof(table));

	printf("%d", solve(0) - 1);

	return 0;
}
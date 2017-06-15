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

std::vector<int> order;
int table[22][22][22];
int n;

//order[idx~끝]까지 확인해야하고 현재 벽장 열린 문이 a,b일 때 최소 이동 횟수
int count(int a, int b, int idx)
{
	if (idx == order.size())
		return 0;

	if (a <= 0 || a > n || b <= 0 || b > n)
		return 987654321;

	if (table[a][b][idx] != -1)
		return table[a][b][idx];

	int& res = table[a][b][idx];

	res = 987654321;

	//지금 벽장 확인 가능하면 다음 걸로 넘어가면 됨
	if (a == order[idx] || b == order[idx])
	{
		idx++;
		//그대로 벽장 안 움직이고 다음으로 가는 경우도 확인
		res = std::min(res, count(a, b, idx));
	}

	//벽장 움직이는 케이스들 확인

	res = std::min(res, 1 + count(a - 1, b, idx));
	res = std::min(res, 1 + count(a + 1, b, idx));
	res = std::min(res, 1 + count(a, b - 1, idx));
	res = std::min(res, 1 + count(a, b + 1, idx));

	return res;
}

int main()
{
	memset(table, -1, sizeof(table));

	scanf("%d", &n);

	int a, b;

	scanf("%d %d", &a, &b);

	int l;
	scanf("%d", &l);

	for (int i = 0; i < l; i++)
	{
		int k;
		scanf("%d", &k);

		order.push_back(k);
	}

	printf("%d", count(a, b, 0));

	return 0;
}
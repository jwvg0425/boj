#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <memory.h>
#include <queue>
#define MAX 987654321


int n, w;
int table[10001][4][3];
int area[10001][2];

int calc(int k, int sfill, int fill)
{
	if (k == n)
	{
		//end case - 남은 것에 따라 처분
		if (sfill == 3)
			return 0;
		else if (sfill == 2)
			if (fill == 1)
				return 0;
			else
				return 1;
		else if (sfill == 1)
			if (fill == 2)
				return 0;
			else
				return 1;
		else
			if (fill > 0)
				return 1;
			if (area[0][0] + area[0][1] <= w)
				return 1;
			else
				return 2;
	}

	if (k > n)
		return 0;

	if (table[k][sfill][fill] != -1)
		return table[k][sfill][fill];

	int& res = table[k][sfill][fill];

	res = MAX;

	bool line = area[k][0] + area[k][1] <= w; // 이쪽 줄 위아래 채우기
	bool up = (area[k][0] + area[(k + 1) % n][0] <= w) && (k < n - 1 || sfill % 2 == 0); //위 옆
	bool down = (area[k][1] + area[(k + 1) % n][1] <= w) && (k < n - 1 || sfill <= 1); //아래 옆

	switch (fill)
	{
	case 0: //위 아래 다 비어있음.
		res = std::min(res, 2 + calc(k + 1, k == 0 ? 3 : sfill, 0));

		if (line)
			res = std::min(res, 1 + calc(k + 1, k == 0 ? 3 : sfill, 0));

		if (up&&down)
			res = std::min(res, 2 + calc(k + 2, k == 0 ? 3 : sfill, 0));
		else if (up)
			res = std::min(res, 2 + calc(k + 1, k == 0 ? 3 : sfill, 1));
		else if (down)
			res = std::min(res, 2 + calc(k + 1, k == 0 ? 3 : sfill, 2));

		break;
	case 1:
		res = std::min(res, 1 + calc(k + 1, k == 0 ? 2 : sfill, 0));

		if (down)
			res = std::min(res, 1 + calc(k + 1, k == 0 ? 2 : sfill, 2));

		break;
	case 2:
		res = std::min(res, 1 + calc(k + 1, k == 0 ? 1 : sfill, 0));

		if (up)
			res = std::min(res, 1 + calc(k + 1, k == 0 ? 1 : sfill, 1));
		break;
	}

	return res;
}



void solve()
{
	memset(table, -1, sizeof(table));

	scanf("%d %d", &n, &w);

	for (int y = 0; y < 2; y++)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &area[i][y]);
		}
	}

	printf("%d\n", std::min({calc(0, 0, 0), calc(0, 0, 1), calc(0, 0, 2), calc(1, 0, 0) }));
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
		solve();

	return 0;
}
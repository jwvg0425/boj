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

int counts[19684];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num = 0;

		for (int j = 0; j < 9; j++)
		{
			int k;
			scanf("%d", &k);
			num = num * 3;
			num += k - 1;
		}

		counts[num]++;
	}

	int min = n + 1;
	int max = -1;

	for (int i = 0; i < 19683; i++)
	{
		//각 경우에 대해 안겹치는 걸 구한다
		//자리마다 하나씩 정해놨으니 안 정해놓은 거 집어넣으면 안 겹치는 건 2^9=512가지 존재
		int sum = 0;
		for (int j = 0; j < 512; j++)
		{
			int ex = 0;
			int icopy = i;
			int jcopy = j;
			for (int k = 0; k < 9; k++)
			{
				ex *= 3;
				ex += ((icopy % 3) + (jcopy % 2 + 1)) % 3;
				icopy /= 3;
				jcopy /= 2;
			}

			sum += counts[ex];
		}

		max = std::max(max, sum);
		min = std::min(min, sum);
	}

	printf("%d %d", min, max);

	return 0;
}
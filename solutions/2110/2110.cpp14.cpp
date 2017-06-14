#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <memory.h>

int main()
{
	int n, c;

	scanf("%d %d", &n, &c);

	std::vector<int> house;

	for (int i = 0; i < n; i++)
	{
		int h;
		scanf("%d", &h);

		house.push_back(h);
	}

	std::sort(house.begin(), house.end());

	int left = 1;
	int right = house.back();

	int max = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int prev = 0;
		int count = 1;

		for (int i = 1; i < house.size(); i++)
		{
			if (house[i] - house[prev] >= mid)
			{
				count++;
				prev = i;
			}
		}

		if (count >= c)
		{
			//설치 가능한 경우 - 간격 늘리기
			max = std::max(max, mid);
			left = mid + 1;
		}
		else
		{
			//불가능한 경우 - 간격 좁히기
			right = mid - 1;
		}
	}

	printf("%d", max);

	return 0;
}
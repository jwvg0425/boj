#include <stdio.h>
#include <algorithm>
#include <vector>

int main()
{
	int N, M;
	std::vector<int> nums;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int t;
		scanf("%d", &t);
		nums.push_back(t);
	}

	std::sort(nums.begin(), nums.end());

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int t;
		scanf("%d", &t);
		if (std::binary_search(nums.begin(), nums.end(), t))
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
}
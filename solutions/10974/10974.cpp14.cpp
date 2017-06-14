#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> vi;

	for (int i = 1; i <= n; i++)
		vi.push_back(i);

	do
	{
		for (auto& i : vi)
			printf("%d ", i);
		printf("\n");
	} while (std::next_permutation(vi.begin(), vi.end()));

	return 0;
}
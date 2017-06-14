#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> vi;

	for (int i = 0; i < n; i++)
	{
		int a;

		scanf("%d", &a);
		vi.push_back(a);
	}

	printf("%d %d", *std::min_element(vi.begin(), vi.end()), 
		*std::max_element(vi.begin(), vi.end()));
}
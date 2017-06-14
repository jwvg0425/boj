#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

int main()
{
	int n;

	scanf("%d", &n);

	std::vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);

		arr.push_back(a);
	}

	std::sort(arr.begin(), arr.end());

	for (auto& a : arr)
	{
		printf("%d\n", a);
	}
}
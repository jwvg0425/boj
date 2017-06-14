#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>

int s, n, count;

int arr[21];

void combSum(int index, int sum)
{
	if (index == n)
		return;

	if (sum + arr[index] == s)
		count++;

	combSum(index + 1, sum + arr[index]);
	combSum(index + 1, sum);
}

int main()
{
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	combSum(0, 0);

	printf("%d", count);

	return 0;
}
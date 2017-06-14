#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>

int count = 0;
int n;
int pos[15] = { 0, };

//x,y칸 놓을 수 있냐
bool placable(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (pos[i] == x)
			return false;

		if (abs(x - pos[i]) == y - i)
			return false;
	}

	return true;
}

void queen(int k)
{
	if (k == n)
	{
		count++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (placable(i, k))
		{
			pos[k] = i;
			queen(k + 1);
		}
	}
}

int main()
{
	scanf("%d", &n);

	queen(0);

	printf("%d", count);

	return 0;
}
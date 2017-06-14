#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int right[] = { 1,1,2,2,2,8 };

int main()
{
	for (int i = 0; i < 6; i++)
	{
		int a;

		scanf("%d", &a);

		printf("%d ", right[i] - a);
	}
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <functional>

int main()
{
	int l, p;

	scanf("%d %d", &l, &p);

	for (int i = 0; i < 5; i++)
	{
		int n;
		scanf("%d", &n);

		printf("%d ", n - l*p);
	}
	
	return 0;
}
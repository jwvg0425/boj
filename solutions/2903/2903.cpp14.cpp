#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int k = 2;

	for (int i = 0; i < n; i++)
		k += k - 1;

	printf("%d", k * k);

	return 0;
}
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
#include <deque>

std::map<std::string, int> seller;

int main()
{
	int sum = 0;
	int k;

	while (~scanf("%d", &k))
	{
		sum += k;
	}

	printf("%d", sum);

	return 0;
}
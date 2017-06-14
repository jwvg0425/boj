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
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d", std::max(std::abs(a - b), std::abs(b - c)) - 1);

	
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <queue>
#include <tuple>
#include <map>
#include <functional>

int main()
{
	int a, b, c, d, p;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);

	printf("%d", std::min(p*a, std::max(p - c, 0)*d + b));

	return 0;
}
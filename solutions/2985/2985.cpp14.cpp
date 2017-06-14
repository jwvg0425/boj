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

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a + b == c)
		printf("%d+%d=%d", a, b, c);
	else if (a - b == c)
		printf("%d-%d=%d", a, b, c);
	else if (a * b == c)
		printf("%d*%d=%d", a, b, c);
	else if (a % b == 0 && a / b == c)
		printf("%d/%d=%d", a, b, c);
	else if (a == b + c)
		printf("%d=%d+%d", a, b, c);
	else if (a == b - c)
		printf("%d=%d-%d", a, b, c);
	else if (a == b * c)
		printf("%d=%d*%d", a, b, c);
	else if (a == b / c)
		printf("%d=%d/%d", a, b, c);
	return 0;
}
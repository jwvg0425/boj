#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int a, b, c, d, e;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	printf("%d", std::min({ a,b,c }) + std::min(d, e) - 50);
}
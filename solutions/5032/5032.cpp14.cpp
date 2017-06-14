#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>
#include<set>

int main()
{
	int e, f, c;
	scanf("%d %d %d", &e, &f, &c);

	e += f;

	int count = 0;

	while (e >= c)
	{
		int can = e / c;
		e %= c;
		e += can;
		count += can;
	}

	printf("%d", count);

	return 0;
}
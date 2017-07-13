#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	while (true)
	{
		float a, b;

		scanf("%f %f", &a, &b);

		if (a == 0 && b == 0)
			break;

		printf("%.3f\n", sqrt(1 - (b*b) / (a*a)));
	}

	return 0;
}
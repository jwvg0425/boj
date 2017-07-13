#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory.h>
#include <stack>

int main()
{
	while(true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		int d = 1;
		int dt = 2;
		int convert = 0;

		while (n > 0)
		{
			convert += (n % 10) * d;
			d *= dt;
			dt++;
			n /= 10;
		}

		printf("%d\n", convert);
	}

	return 0;
}
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>

int main()
{
	while(true)
	{
		int n;
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d ", n);

		while (n >= 10)
		{
			int k = n % 10;
			n /= 10;

			while (n > 0)
			{
				k *= n % 10;
				n /= 10;
			}
			n = k;
			printf("%d ", n);
		}

		printf("\n");
	}

	return 0;
}
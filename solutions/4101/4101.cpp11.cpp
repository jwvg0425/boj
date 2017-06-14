#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{

	while (true)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (a == 0 && b == 0)
			return 0;

		printf("%s\n", a > b ? "Yes" : "No");
	}
}
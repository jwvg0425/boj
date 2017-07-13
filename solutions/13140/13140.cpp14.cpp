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

int n;

//d,e,h,l,o,r,w
int digits[7];

bool find(int idx)
{
	if (idx == 7)
	{
		int a = digits[2] * 10000 + digits[1] * 1000 + digits[3] * 100 + digits[3] * 10 + digits[4];
		int b = digits[6] * 10000 + digits[4] * 1000 + digits[5] * 100 + digits[3] * 10 + digits[0];

		if (a + b == n)
		{
			printf("  %d\n", a);
			printf("+ %d\n", b);
			printf("-------\n");
			printf("%7d", n);
			return true;
		}
		return false;
	}

	int start = 0;

	if (idx == 2 || idx == 6)
		start = 1;

	for (int i = start; i < 10; i++)
	{
		if (std::find(digits, digits + idx, i) != digits + idx)
		{
			continue;
		}

		digits[idx] = i;
		if (find(idx + 1))
			return true;
	}

	return false;
}

int main()
{
	scanf("%d", &n);

	if (!find(0))
		printf("No Answer");

	return 0;
}
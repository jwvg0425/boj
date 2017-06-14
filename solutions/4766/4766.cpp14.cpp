#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

int main()
{
	float prev;
	scanf("%f", &prev);

	while (true)
	{
		float now;
		scanf("%f", &now);

		if (now == 999)
			break;

		printf("%.2f\n", now - prev);
		prev = now;
	}

	return 0;
}
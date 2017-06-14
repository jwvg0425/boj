#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int sum = 0;
	int count[1001] = { 0, };
	int maxVal = 0;

	for (int i = 0; i < 10; i++)
	{
		int val;
		scanf("%d", &val);
		sum += val;
		count[val]++;
		if (count[val] > count[maxVal])
			maxVal = val;
	}

	printf("%d\n%d", sum / 10, maxVal);
}
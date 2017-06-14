#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int mult = a*b*c;

	int digit[10] = { 0, };

	while (mult > 0)
	{
		digit[mult % 10]++;
		mult /= 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", digit[i]);
}
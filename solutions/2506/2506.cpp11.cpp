#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;
	int score = 0;
	int val = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int s;
		scanf("%d", &s);
		if (s == 0)
			val = 0;
		else
			val++;
		score += val;
	}

	printf("%d", score);
}
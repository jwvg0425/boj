#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>

int main()
{
	int n;

	scanf("%d", &n);

	printf("%s", n % 2 == 0 ? "SK" : "CY");
	return 0;
}
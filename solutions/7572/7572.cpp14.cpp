#include<stdio.h>
#include<memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int n;

	scanf("%d", &n);

	int a = (n + 8) % 12, b = (n + 6) % 10;

	printf("%c%d", a + 'A', b);

	return 0;
}
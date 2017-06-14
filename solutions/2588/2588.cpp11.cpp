#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int A, B;

	scanf("%d %d", &A, &B);

	printf("%d\n%d\n%d\n%d",
		A*(B % 10),
		A*((B / 10) % 10),
		A*((B / 100) % 10),
		A*B);
}
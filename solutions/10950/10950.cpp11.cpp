#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int A, B;

		scanf("%d %d", &A, &B);

		printf("%d\n", A + B);
	}
}
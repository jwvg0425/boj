#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int main()
{
	int suma = 0, sumb = 0;

	bool yes = false;

	int as[9];
	int bs[9];

	for (int i = 0; i < 9; i++)
		scanf("%d", &as[i]);

	for (int i = 0; i < 9; i++)
		scanf("%d", &bs[i]);

	for (int i = 0; i < 9; i++)
	{
		if (suma + as[i] > sumb)
		{
			yes = true;
		}

		suma += as[i];
		sumb += bs[i];
	}

	printf("%s", yes ? "Yes" : "No");

	return 0; 
}
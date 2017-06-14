#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

int main()
{
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		char buffer[10];

		scanf("%s", buffer);

		for (int j = 0; j < 8; j++)
		{
			if (buffer[j] == 'F' && (i + j) % 2 == 0)
				count++;
		}
	}

	printf("%d", count);
}
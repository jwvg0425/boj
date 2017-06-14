
#include <stdio.h>
#include <string.h>

int main()
{
	char str[51];
	int h = 0;

	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++)
	{
		if (i == 0 || str[i] != str[i - 1])
			h += 10;
		else
			h += 5;
	}

	printf("%d", h);

	return 0;
}
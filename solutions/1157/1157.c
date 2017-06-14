#include<stdio.h>
#include<string.h>

int b[27];

int main(void)
{
	char a[1000005];
	int i, m = 0;

	scanf("%s", a);
	
	for (i = 0; a[i]!='\0'; i++)b[(a[i] - 'A') % 32]++;

	for (i = 0; i < 27; i++)
	{
		if (b[i]>b[m])m = i;
	}
	for (i = 0; i < 27; i++)
	{
		if (b[i] == b[m] && i!=m)
		{
			printf("?");
			return 0;
		}
	}
	printf("%c", m + 'A');
}
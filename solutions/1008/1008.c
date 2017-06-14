#include<stdio.h>

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%.16lf", (double)a / b);
}
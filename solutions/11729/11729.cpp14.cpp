#include <stdio.h>
#include <algorithm>

void hanoi(int n, int x, int y, int z) 
{ 
	if (n>0) 
	{ 
		hanoi(n - 1, x, z, y); 
		printf("%d %d\n", x, z); 
		hanoi(n - 1, y, x, z); 
	} 
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", (1 << n) - 1);
	hanoi(n, 1, 2, 3);

	return 0;
}
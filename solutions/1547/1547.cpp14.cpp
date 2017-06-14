#include<stdio.h>
#include <queue>
#include <vector>

int main()
{
	int m;
	bool pos[4] = { false,true,false,false };

	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		std::swap(pos[a], pos[b]);
	}

	for (int i = 1; i <= 3; i++)
	{
		if (pos[i])
			printf("%d",i);
	}
	return 0;
}
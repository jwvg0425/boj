#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <queue>
#include <stack>
#include <memory.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		std::string a, b;

		std::cin >> a >> b;

		printf("Distances: ");

		for (int i = 0; i < a.size(); i++)
		{
			int k = b[i] - a[i];

			if (k < 0)
				k += 26;
			printf("%d ", k);
		}
		printf("\n");
	}

	return 0;
}
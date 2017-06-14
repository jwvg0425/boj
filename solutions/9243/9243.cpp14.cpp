#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
int main()
{
	int n;

	scanf("%d", &n);

	std::string a, b;

	std::cin >> a >> b;

	for (int i = 0; i < a.size(); i++)
	{
		if ((n % 2 == 0) != (a[i] == b[i]))
		{
			printf("Deletion failed");
			return 0;
		}
	}

	printf("Deletion succeeded");

	return 0;
}
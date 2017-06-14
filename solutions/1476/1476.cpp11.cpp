#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>

int main()
{
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	int ne = 1, ns = 1, nm = 1, year = 1;

	while (ns != s || ne != e || nm != m)
	{
		year++;
		ns++;
		ne++;
		nm++;

		if (ne > 15)
			ne = 1;

		if (ns > 28)
			ns = 1;

		if (nm > 19)
			nm = 1;
	}

	printf("%d", year);

	return 0;
}
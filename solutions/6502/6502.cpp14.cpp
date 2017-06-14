#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>

int main()
{
	int i = 1;
	while (true)
	{
		int r;
		scanf("%d", &r);

		if (r == 0)
			break;

		int w, l;
		scanf("%d %d", &w, &l);

		if (r*r * 4 >= w *w + l *l)
			printf("Pizza %d fits on the table.\n", i);
		else
			printf("Pizza %d does not fit on the table.\n", i);

		i++;
	}

	return 0;
}
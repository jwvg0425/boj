#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <tuple>

int main()
{
	int n, w, h;
	scanf("%d %d %d", &n, &w, &h);

	for (int i = 0; i < n; i++)
	{
		int l;
		scanf("%d", &l);
		printf("%s\n", l*l <= w*w + h*h ? "DA" : "NE");
	}

	return 0;
}
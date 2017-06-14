#include <stdio.h>
#include <memory.h>
#include <algorithm>

int main()
{
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	printf("%d", std::min({ x, y, w - x, h - y }));
}
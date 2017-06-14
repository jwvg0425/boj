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

int main()
{
	int w, h;
	int p, q, t;

	scanf("%d %d %d %d %d", &w, &h, &p, &q, &t);


	int nx = p + t;
	int ny = q + t;

	int sidex = nx / w;
	int sidey = ny / h;

	int xpos = (sidex % 2 == 0) ? (nx - sidex * w) : (w - (nx % w));
	int ypos = (sidey % 2 == 0) ? (ny - sidey * h) : (h - (ny % h));

	printf("%d %d", xpos, ypos);

	return 0;
}
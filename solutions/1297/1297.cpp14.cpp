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
	int r, wr, hr;

	scanf("%d %d %d", &r, &wr, &hr);

	int k = r*r;
	int t = wr*wr + hr * hr;

	double c = sqrt(k / double(t));
	int w = c*wr;
	int h = c*hr;

	printf("%d %d", w, h);

	return 0;
}
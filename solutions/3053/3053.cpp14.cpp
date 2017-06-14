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
#define PI 3.1415926535897932384626433832795028841971

int main()
{
	int R;
	scanf("%d", &R);

	printf("%.6lf %.6lf", PI * R * R, 2.0 * R * R);

	return 0;
}
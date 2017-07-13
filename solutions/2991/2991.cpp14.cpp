#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <memory.h>


int a, b, c, d;

int count(int k)
{
	int res = 0;

	if (k % (a + b) != 0 && k % (a + b) <= a)
		res++;

	if (k % (c + d) != 0 && k % (c + d) <= c)
		res++;

	return res;
}


int main() 
{
	int p, m, n;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	scanf("%d %d %d", &p, &m, &n);

	printf("%d\n%d\n%d", count(p), count(m), count(n));
}
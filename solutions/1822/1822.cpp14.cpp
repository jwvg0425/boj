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

int main()
{
	std::set<int> a;
	int na, nb;

	scanf("%d %d", &na, &nb);

	for (int i = 0; i < na; i++)
	{
		int k;
		scanf("%d", &k);
		a.insert(k);
	}

	for (int i = 0; i < nb; i++)
	{
		int k;
		scanf("%d", &k);
		a.erase(k);
	}

	printf("%d\n", a.size());

	for (auto& k : a)
		printf("%d ", k);

	return 0;
}
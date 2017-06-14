#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <math.h>

int main()
{
	int N;

	std::vector<int> v;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}

	std::sort(v.begin(), v.end());

	for (auto& i : v)
	{
		printf("%d\n", i);
	}
}
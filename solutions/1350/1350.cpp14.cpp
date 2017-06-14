#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>

int main()
{
	int n;
	std::vector<int> files;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int f;
		scanf("%d", &f);
		files.push_back(f);
	}

	long long int disk = 0;
	int cluster = 0;

	scanf("%d", &cluster);

	for (auto& f : files)
	{
		int num = (f + cluster - 1) / cluster;
		disk += num * cluster;
	}

	printf("%lld", disk);

	return 0;
}
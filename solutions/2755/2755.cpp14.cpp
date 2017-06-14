#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <memory.h>

std::map<char, float> score =
{
	{ 'A', 4.0f },
	{ 'B', 3.0f },
	{ 'C', 2.0f },
	{ 'D', 1.0f },
	{ 'F', 0.0f },
	{ '+', 0.3f },
	{ '0', 0.0f },
	{ '-', -0.3f }
};

int main()
{
	int n;
	scanf("%d", &n);

	float sum = 0.0f;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		std::string name;
		int k;
		std::string s;

		std::cin >> name >> k >> s;

		for (auto& c : s)
		{
			sum += k * score[c];
		}

		count += k;
	}

	printf("%.2f", sum / count);

	return 0;
}
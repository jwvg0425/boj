#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <memory>
#include <time.h>
#include <tuple>


int count(std::string str, int off, int idx, std::vector<std::string> cand)
{
	if (off >= str.size())
		return cand.size();

	std::string cs;

	//이 경우 후보 여러 개
	if (str[off] == '(')
	{
		for (off++; str[off] != ')'; off++)
		{
			cs.push_back(str[off]);
		}
	}
	else
	{
		cs.push_back(str[off]);
	}

	int sum = 0;

	std::vector<std::string> nextCand;

	for(auto& k : cs)
	{
		for (auto& c : cand)
		{
			if (c[idx] == k)
				nextCand.push_back(c);
		}
	}

	return count(str, off + 1, idx + 1, nextCand);
}

int main()
{
	int l, d, n;
	scanf("%d %d %d", &l, &d, &n);

	std::vector<std::string> dict;

	for (int i = 0; i < d; i++)
	{
		std::string word;

		std::cin >> word;

		dict.push_back(word);
	}

	for (int i = 1; i <= n; i++)
	{
		std::string str;

		std::cin >> str;

		printf("Case #%d: %d\n", i, count(str, 0, 0, dict));
	}

	return 0;
}
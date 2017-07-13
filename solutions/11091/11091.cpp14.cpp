#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <memory.h>

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++)
	{
		std::string word;
		std::getline(std::cin, word);

		int counts[26] = { 0, };

		for (auto& c : word)
		{
			if (c >= 'a' && c <= 'z')
				counts[c - 'a']++;
			else if (c >= 'A' && c <= 'Z')
				counts[c - 'A']++;
		}

		std::string missing;
		for (int i = 0; i < 26; i++)
		{
			if (counts[i] == 0)
				missing.push_back(i + 'a');
		}

		if (missing.size() == 0)
			printf("pangram\n");
		else
			std::cout << "missing " << missing << std::endl;
	}
	return 0;
}
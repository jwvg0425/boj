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
	std::string document;
	std::string word;

	std::getline(std::cin, document);
	std::getline(std::cin, word);

	int idx = 0;
	int count = 0;
	while ((idx = document.find(word, idx)) != std::string::npos)
	{
		count++;
		idx += word.size();
	}

	printf("%d", count);

	return 0;
}
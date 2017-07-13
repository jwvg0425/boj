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

using ii = std::pair<int, int>;

int main()
{
	int k;
	std::string numbers = "0123456789";
	std::vector<std::string> v;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		std::string t;

		std::cin >> t;

		v.push_back(t);
	}

	std::string min, max;

	do
	{
		bool isOk = true;
		for (int i = 0; i < v.size(); i++)
		{
			if ((v[i][0] == '>' && numbers[i] <= numbers[i + 1])
				|| (v[i][0] == '<' && numbers[i] >= numbers[i + 1]))
			{
				isOk = false;
				break;
			}
		}

		if (!isOk)
			continue;

		std::string sub = numbers.substr(0, k + 1);

		if (min.empty() || min > sub)
			min = sub;

		if (max.empty() || max < sub)
			max = sub;

	} while (std::next_permutation(numbers.begin(), numbers.end()));

	std::cout << max << std::endl;
	std::cout << min << std::endl;

	return 0;
}
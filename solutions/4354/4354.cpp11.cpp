#include <iostream>
#include <vector>
#include <string>

int main()
{
	while (true)
	{
		std::string text;

		std::cin >> text;

		if (text.find('.') != std::string::npos)
		{
			return 0;
		}

		std::vector<int> pi(text.size(), 0);

		int begin = 1, matched = 0;

		while (begin + matched < text.size())
		{
			if (text[begin + matched] == text[matched])
			{
				matched++;
				pi[begin + matched - 1] = matched;
			}
			else if (matched == 0)
			{
				begin++;
			}
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}

		int max = text.size() - pi[text.size() - 1];

		if (text.size() % max == 0)
			std::cout << text.size() / max << std::endl;
		else
			std::cout << 1 << std::endl;
	}

	return 0;
}
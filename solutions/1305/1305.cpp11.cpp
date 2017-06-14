#include <iostream>
#include <string>
#include <vector>

int main()
{
	int L;
	std::string text;

	std::cin >> L >> text;

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

	std::cout << L - pi[L - 1];

	return 0;
}
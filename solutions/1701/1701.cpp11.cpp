#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> partial(const std::string& text, int offset)
{
	std::vector<int> pi;

	pi.resize(text.size() - offset, 0);

	int begin = 1, matched = 0;

	while (begin + matched < text.size() - offset)
	{
		if (text[offset + begin + matched] == text[offset + matched])
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

	return pi;
}
int max = 0;

//offset 위치부터 시작하는 부분 문자열 찾는다
int search(const std::string& text, int offset)
{
	auto pi = partial(text, offset);

	for (int size = std::max(1, max); size <= text.size() - offset; size++)
	{
		int count = 0;
		int begin = 0, matched = 0;

		while (begin < text.size())
		{
			if (matched < size && text[begin + matched] == text[offset + matched])
			{
				matched++;

				if (matched == size)
				{
					count++;
					if (count >= 2)
						break;
				}
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

		if (count >= 2)
			max = size;
		else
			return max;
	}

	return max;
}

int main()
{
	std::string text;

	std::cin >> text;

	for (int i = 0; i < text.size(); i++)
	{
		max = std::max(search(text, i), max);
	}

	std::cout << max;

	return 0;
}
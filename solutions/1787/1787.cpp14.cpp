#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n;
	std::string text;

	std::cin >> n >> text;

	std::vector<int> pi(text.size() + 1, 0);

	int begin = 1, matched = 0;

	while (begin + matched < text.size())
	{
		if (text[begin + matched] == text[matched])
		{
			matched++;
			pi[begin + matched] = matched;
		}
		else if (matched == 0)
		{
			begin++;
		}
		else
		{
			begin += matched - pi[matched];
			matched = pi[matched];
		}
	}

	std::vector<int> ppi = pi;

	long long int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		int j = pi[i];

		while (ppi[j] != 0)
		{
			j = ppi[j];
		}

		ppi[i] = j;

		//이 경우는 접두사 == 접미사인 경우가 없다는 이야기
		if (j == 0)
			continue;

		int k = i - j;

		if (k >= (i + 1) / 2)
			sum += k;
	}

	std::cout << sum;

	return 0;
}
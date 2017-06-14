#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	int N, S;
	scanf("%d %d", &N, &S);
	
	std::vector<int> numbers = { 0};

	for (int i = 0; i < N;i++)
	{
		int num;
		scanf("%d", &num);

		numbers.emplace_back(numbers.back() + num);
	}

	int left = 0, right = 1;
	int length = 987654321;

	while (right < numbers.size())
	{
		if (numbers[right] - numbers[left] >= S)
		{
			if (right - left < length)
				length = right - left;

			left++;
		}
		else
		{
			right++;
		}
	}

	printf("%d", length == 987654321 ? 0 : length);

	return 0;
}
#include <stdio.h>
#include <math.h>
#include <algorithm>

int N;
int tab[1001];

int answer(int start, int end)
{
	if (start >= end)
		return 0;

	if (start + 1 == end)
		return abs(tab[start]);

	int count = 0;
	int nowStart = start;
	int min = tab[start];

	for (int i = start; i <= end; i++)
	{
		//연속된 같은 부호들
		if (i != end && tab[i] * tab[nowStart] > 0)
		{
			//최솟값 갱신
			min = ((min < 0) ?-1 : 1) * std::min(abs(tab[i]), abs(min));
		}
		else // 다른 부호 만남 - 구간 끝
		{
			count += abs(min);
			for (int j = nowStart; j < i; j++)
			{
				tab[j] -= min;
			}

			int subStart = nowStart;
			for (int j = nowStart; j <= i; j++)
			{
				if (j == i || tab[j] == 0)
				{
					count += answer(subStart, j);
					subStart = j;
				}
			}
			nowStart = i;
			min = tab[nowStart];
		}
	}

	return count;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tab[i]);
	}

	for (int i = 0; i < N; i++)
	{
		int goal;
		scanf("%d", &goal);
		tab[i] = goal - tab[i];
	}

	printf("%d", answer(0, N));
}
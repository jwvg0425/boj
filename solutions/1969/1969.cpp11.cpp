#include <stdio.h>

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	char str[1001][51];

	int distance = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", str[i]);
	}

	for (int i = 0; i < M; i++)
	{
		int num[27] = { 0, };
		
		for (int j = 0; j < N; j++)
		{
			num[str[j][i] - 'A']++;
		}

		char gen[5] = "ACGT";
		int maxIdx = 0;

		for (int j = 1; j < 4; j++)
		{
			if (num[gen[maxIdx] - 'A'] < num[gen[j] - 'A'])
			{
				maxIdx = j;
			}
		}

		distance += N - num[gen[maxIdx] - 'A'];

		printf("%c", gen[maxIdx]);
	}

	printf("\n%d", distance);

	return 0;
}
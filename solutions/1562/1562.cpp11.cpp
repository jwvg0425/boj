#include <stdio.h>
#include <memory.h>
#include <string>
#define MOD 1000000000

//table[n][s][bit] = 길이 n에 대해 시작 숫자가 s. bit는 0 -> 위아래 다 안 방문, 1 -> 0 방문, 2 -> 9 방문
int table[101][11][4];

int answer(int n, int s, int bit)
{
	if (s < 0 || s > 9) return 0;

	int& res = table[n][s][bit];

	if (res != -1)
		return res;

	if (s == 0)
		bit |= 1;

	if (s == 9)
		bit |= 2;

	if (n == 1)
		return (bit == 3) ? 1 : 0;

	res = answer(n - 1, s - 1, bit);
	res = (res + answer(n - 1, s + 1, bit)) % MOD;

	return res;
}

int main()
{
	int N;
	scanf("%d", &N);
	memset(table, -1, sizeof(table));

	int res = 0;

	for (int start = 1; start <= 9; start++)
	{
		res = (res + answer(N, start, 0)) % MOD ;
	}

	printf("%d", res);

	return 0;
}
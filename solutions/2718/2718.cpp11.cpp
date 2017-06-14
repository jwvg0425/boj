#include <stdio.h>
#include <map>
#include <memory.h>

int table[50][16] = { 0, };

//전체 길이 n, 현재 작업하고 있는 줄 상태 last.
int count(int n, int last)
{
	int& res = table[n][last];

	if (res != -1)
		return res;

	//다 채움	
	if (n == 1)
	{
		if (last == 0 || last == 3 || last == 9 || last == 12 || last == 15)
			return 1; // 채울 수 있는 경우
		else
			return 0; // 불가능한 경우
	}

	//last는 4비트짜리. 현재 마지막 y줄의 어느어느 칸이 차 있는지 확인.
	//걍 노가다 하자 1 2 4 8
	switch (last)
	{
	case 0:
		res = count(n - 1, 15) + count(n - 1, 3) + count(n - 1, 9) + count(n - 1, 12) + count(n - 1, 0);
		break;
	case 3:
		res = count(n - 1, 12) + count(n - 1, 0);
		break;
	case 6:
		res = count(n - 1, 9);
		break;
	case 9:
		res = count(n - 1, 6) + count(n - 1, 0);
		break;
	case 12:
		res = count(n - 1, 3) + count(n - 1, 0);
		break;
	case 15:
		res = count(n - 1, 0);
		break;
	}

	return res;
}

void solve()
{
	int N;
	scanf("%d", &N);

	printf("%d\n", count(N, 0));
}

int main()
{
	memset(table, -1, sizeof(table));
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		solve();
	}

	return 0;
}
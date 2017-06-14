#include<vector>
#include <stdio.h>
#include<memory.h>

long long table[10001][101];

class Solution
{
public:
	std::vector<int> currencies;

	//nowMoney 원을 offset 이후 currecncies로 나타낼 수 있는 경우의 수
	long long answer(int nowMoney, int offset)
	{
		if (nowMoney == 0)
			return 1;

		if (offset >= currencies.size() || nowMoney < 0)
			return 0;

		long long& res = table[nowMoney][offset];

		if (res != -1)
			return res;

		return res = answer(nowMoney - currencies[offset], offset) + answer(nowMoney, offset + 1);
	}

	long long solution(std::vector<int> c, int wantMoney)
	{
		currencies = c;
		memset(table, -1, sizeof(table));

		return answer(wantMoney, 0);
	}
};

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int N, M;
		std::vector<int> c;

		scanf("%d", &N);

		for (int j = 0; j < N; j++)
		{
			int a;

			scanf("%d", &a);

			c.push_back(a);
		}

		scanf("%d", &M);

		Solution s;

		printf("%lld\n", s.solution(c, M));

	}
}
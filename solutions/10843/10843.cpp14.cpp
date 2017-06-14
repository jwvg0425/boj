#include <cstdio>
#include <vector>

enum class RSP
{
	Rock,
	Scissors,
	Paper,
	None
};

enum class Result
{
	Win,
	Draw,
	Lose
};

Result versus(RSP lhs, RSP rhs)
{
	if (lhs == rhs)
		return Result::Draw;

	switch (rhs)
	{
	case RSP::Rock:
		if (lhs == RSP::Paper)
			return Result::Win;
	case RSP::Scissors:
		if (lhs == RSP::Rock)
			return Result::Win;
	case RSP::Paper:
		if (lhs == RSP::Scissors)
			return Result::Win;
	}

	return Result::Lose;
}

RSP toRsp(int num)
{
	switch (num)
	{
	case 0:
		return RSP::Scissors;
	case 1:
		return RSP::Rock;
	case 2:
		return RSP::Paper;;
	}

	return RSP::None;
}

int main()
{
	std::vector<RSP> my;
	std::vector<RSP> enemy;

	int N;

	std::scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		std::scanf("%d %d", &a, &b);

		my.push_back(toRsp(a));
		enemy.push_back(toRsp(b));
	}

	std::printf(("1"));

	return 0;
}
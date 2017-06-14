#include <stdio.h>
#include <vector>
#include <map>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int sx[] = { 0,3,0,0 };
int sy[] = { 0,0,0,3 };
int ix[] = { 1,-1,1,1 };
int iy[] = { 1,1,1,-1 };

int index(int x, int y)
{
	return 2 * (y * 4 + x);
}

int get(unsigned board, int x, int y)
{
	return (board >> index(x,y)) % 4;
}

void set(unsigned* board, int x, int y, int type)
{
	*board &= ~(3 << index(x, y));
	*board |= (type << index(x,y));
}

void add(unsigned board, int type, std::vector<unsigned>& cand)
{
	int count = 0;

	for (int y = 1; y <= 2; y++)
	{
		for (int x = 1; x <= 2; x++)
		{
			if (get(board, x, y) != 0)
				count++;
		}
	}

	switch (count)
	{
	case 0:
		for (int y = 1; y <= 2; y++)
		{
			for (int x = 1; x <= 2; x++)
			{
				unsigned push = board;
				set(&push, x, y, type);
				cand.push_back(push);
			}
		}
		break;
	case 1:
		for (int y = 1; y <= 2; y++)
		{
			for (int x = 1; x <= 2; x++)
			{
				if (get(board, x , y) != 0)
				{
					unsigned push = board;
					set(&push, 3 - x, 3 - y, type);
					cand.push_back(push);
				}
			}
		}
		break;
	case 2:
	case 3:
		for (int y = 1; y <= 2; y++)
		{
			for (int x = 1; x <= 2; x++)
			{
				if (get(board, x, y) == 0)
				{
					unsigned push = board;
					set(&push, x, y, type);
					cand.push_back(push);
				}
			}
		}
		break;
	case 4:
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (y >= 1 && y <= 2 && x >= 1 && x <= 2)
					continue;

				if (get(board, x, y) == 0)
				{
					unsigned push = board;
					set(&push, x, y, type);
					cand.push_back(push);
				}
			}
		}
		break;
	}
}

unsigned turn(unsigned board, int dir)
{
	for (int y = sy[dir]; y >= 0 && y < 4; y += iy[dir])
	{
		for (int x = sx[dir]; x >= 0 && x < 4; x+= ix[dir])
		{
			int nx = x;
			int ny = y;
			int px = nx + dx[dir];
			int py = ny + dy[dir];

			if (get(board, nx, ny) != 0)
			{
				while (px >= 0 && px < 4 && py >= 0 && py < 4 &&
					get(board, px, py) == 0)
				{
					set(&board, px, py, get(board, nx, ny));
					set(&board, nx, ny, 0);
					nx = px;
					ny = py;
					px = nx + dx[dir];
					py = ny + dy[dir];
				}
			}
		}
	}

	return board;
}

void solve()
{
	int N;
	std::vector<char> command;
	std::map<unsigned, double> arr[17];

	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		char c;

		scanf(" %c", &c);
		command.push_back(c);
	}

	scanf("\n");

	char fin[4][5];

	for (int y = 0; y < 4; y++)
	{
		scanf("%s", fin[y]);
	}

	unsigned answer = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			int type = 0;
			switch (fin[y][x])
			{
			case 'E':
				type = 0;
				break;
			case 'W':
				type = 1;
				break;
			case 'G':
				type = 2;
				break;
			}
			set(&answer, x, y, type);
		}
	}

	arr[0][0] = 1.0;

	for (int i = 1; i <= N; i++)
	{
		char c = command[i - 1];

		for (auto& b : arr[i - 1])
		{
			std::vector<unsigned> cands;

			switch (c)
			{
			case 'W':
				add(b.first, 1, cands);
				break;
			case 'G':
				add(b.first, 2, cands);
				break;
			case 'T':
				arr[i][turn(b.first, UP)] += b.second;
				break;
			case 'L':
				arr[i][turn(b.first, LEFT)] += b.second;
				break;
			case 'B':
				arr[i][turn(b.first, DOWN)] += b.second;
				break;
			case 'R':
				arr[i][turn(b.first, RIGHT)] += b.second;
				break;
			}

			for (auto& cand : cands)
			{
				arr[i][cand] += b.second / cands.size();
			}
		}
	}

	printf("%f\n", arr[N][answer]);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
		solve();
}
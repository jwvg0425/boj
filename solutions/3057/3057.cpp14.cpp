#include <stdio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);

	bool ok22[301][301] = { false, };
	bool ok11[301][301] = { false, };

	std::vector<std::string> memory;

	for (int i = 0; i < r; i++)
	{
		std::string str;

		std::cin >> str;
		memory.push_back(str);
	}

	int max = -1;

	//처음 프레임들 초기화
	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
		{
			ok11[x][y] = true;

			if (x < r - 1 && y < c - 1)
			{
				ok22[x][y] = (memory[x][y] == memory[x + 1][y + 1] &&
					memory[x + 1][y] == memory[x][y + 1]);

				if (ok22[x][y])
					max = 2;
			}
		}
	}

	for (int frame = 3; frame <= std::min(r, c); frame++)
	{
		for (int x = 0; x <= r - frame; x++)
		{
			for (int y = 0; y <= c - frame; y++)
			{
				if (frame % 2 == 0 && !ok22[x + 1][y + 1])
				{
					ok22[x][y] = false;
					continue;
				}

				if (frame % 2 == 1 && !ok11[x + 1][y + 1])
				{
					ok11[x][y] = false;
					continue;
				}

				//frame 체크
				bool ok = true;

				for (int i = 0; i < frame; i++)
				{
					if (memory[x][y + i] != memory[x + frame - 1][y + frame - 1 - i] ||
						memory[x + i][y] != memory[x + frame - 1 - i][y + frame - 1])
					{
						ok = false;
						break;
					}
				}

				if (ok)
				{	
					max = frame;
				}
				
				if ( frame % 2 == 0)
				{
					ok22[x][y] = ok;
				}
				else
				{
					ok11[x][y] = ok;
				}
			}
		}
	}

	printf("%d", max);

	return 0;
}
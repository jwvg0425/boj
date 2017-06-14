#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <bitset>
#include <memory.h>

int maxHeight[401][401];

int main()
{
	int r, c;

	scanf("%d %d", &r, &c);

	std::vector<std::string> map;

	for (int i = 0; i < r; i++)
	{
		std::string str;

		std::cin >> str;
		map.push_back(str);
	}

	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
		{
			if (map[x][y] != '.')
				continue;

			//각 지점에서 시작해서 밑으로 뻗을 수 있는 최대 높이 저장해 둠
			int count = 0;
			for (int h = y; h < c; h++)
			{
				if (map[x][h] != '.')
					break;

				count++;
			}

			maxHeight[x][y] = count;
		}
	}

	int maxNum = 0;

	for (int x = 0; x < r; x++)
	{
		for (int y = 0; y < c; y++)
		{
			if (map[x][y] != '.')
				continue;

			//모든 지점에서, 최대한 크게 만들 수 있는 모든 직사각형을 검사
			int height = c;

			for (int w = 0; w < r - x && map[x+w][y] == '.'; w++)
			{
				height = std::min(height, maxHeight[x + w][y]);
				int num = (w + height + 1) * 2;

				maxNum = std::max(maxNum, num);
			}
			
		}
	}

	printf("%d", std::max(0, maxNum - 1));

	return 0;
}
#include <stdio.h>

int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int H, W;
		char board[11][12];
		scanf("%d %d", &H, &W);

		for (int y = 0; y < H; y++)
		{
			scanf("%s", board[y]);
		}

		for (int y = 0; y < H; y++)
		{
			for (int x = W - 1; x >= 0; x--)
			{
				printf("%c", board[y][x]);
			}
			puts("");
		}
	}
}
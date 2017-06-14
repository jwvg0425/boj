#include<stdio.h>
#include<vector>
#include<algorithm>

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int arr[5];

		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[j]);

		std::sort(arr, arr + 5);

		if (arr[3] - arr[1] >= 4)
			printf("KIN\n");
		else
			printf("%d\n", arr[1] + arr[2] + arr[3]);
	}


	return 0;
}
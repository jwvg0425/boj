#include <stdio.h>
#include <memory.h>
#include <algorithm>

int main()
{
	int arr[3];

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	std::sort(arr, arr + 3);

	printf("%d", arr[1]);
}
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int arr[3];

	scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);

	std::sort(arr, arr + 3);

	printf("%d %d %d", arr[0], arr[1], arr[2]);
}
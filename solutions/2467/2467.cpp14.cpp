#include <stdio.h>
#include <algorithm>
 
int main()
{
    int N;
    int arr[100000];
 
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    int l = 0, r = N - 1;
    int ansl = 0, ansr = N - 1;
 
    while (true)
    {
        int ans = abs(arr[ansl] + arr[ansr]);
 
        if (abs(arr[l] + arr[r]) < ans)
        {
            ansl = l;
            ansr = r;
        }
 
        if (l + 1 == r)
            break;
 
        if (abs(arr[l + 1] + arr[r]) < abs(arr[l] + arr[r - 1]))
        {
            l++;
        }
        else
        {
            r--;
        }
    }
 
    printf("%d %d", arr[ansl], arr[ansr]);
}
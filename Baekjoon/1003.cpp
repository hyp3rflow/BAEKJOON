#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;

int arr[42][2];

int main()
{
    scanf("%d", &T);

    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;

    for (int i = 2; i < 42; i++)
    {
        arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
        arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
    }

    for (int i = 0; i < T; i++)
    {
        scanf(" %d", &N);
        printf("%d %d\n", arr[N][0], arr[N][1]);
    }

    return 0;
}
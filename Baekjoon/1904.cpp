#include <cstdio>

using namespace std;

int N, dp[(int)1e6 + 7] = {0, 1, 2};

int main()
{
    scanf("%d", &N);

    for (int i = 3; i < (int)1e6 + 7; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    printf("%d", dp[N]);

    return 0;
}
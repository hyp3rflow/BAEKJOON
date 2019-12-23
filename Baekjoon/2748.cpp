#include <cstdio>

using namespace std;

typedef long long ll;

int N;

ll dp[100] = {0, 1, 1};

int main()
{
    for (int i = 3; i < 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    scanf("%d", &N);
    printf("%lld", dp[N]);
}
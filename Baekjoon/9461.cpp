#include <cstdio>

using namespace std;

typedef long long ll;

int N;
ll dp[110] = {0, 1, 1};

int main()
{
    scanf("%d", &N);

    for (int i = 3; i < 110; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < N; i++)
    {
        int T;
        scanf(" %d", &T);
        printf("%lld\n", dp[T]);
    }

    return 0;
}
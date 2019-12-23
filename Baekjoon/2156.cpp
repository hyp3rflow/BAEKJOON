#include <cstdio>
#include <algorithm>

using namespace std;

int dp[10010], v[10010], N;

int main()
{
    int N, m = -1;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &v[i]);

        if (i > 1)
        {
            if (i > 2)
            {
                // dp[k] -> 꼭 k의 와인을 마실 필요는 없다.. dp[i-1] 빼먹어서 틀림
                dp[i] = max(max(dp[i - 2] + v[i], dp[i-1]), dp[i - 3] + v[i - 1] + v[i]);
            }
            else
            {
                dp[i] = max(dp[i - 2] + v[i], v[i - 1] + v[i]);
            }
        }
        else
            dp[i] = v[i];

        m = max(m, dp[i]);
    }

    printf("%d", m);
}
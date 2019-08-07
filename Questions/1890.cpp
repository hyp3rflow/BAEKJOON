#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int n, arr[110][110];
long long dp[110][110];
int INF = 1e9;

int main(){
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
            dp[i][j] = INF;
        }
    }

    dp[1][1] = 1;
    dp[n][n] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int current = arr[i][j];
            if(dp[i][j] == INF) continue;
            if(current == 0) continue;

            if(dp[i+current][j] == INF) dp[i+current][j] = dp[i][j];
            else dp[i+current][j] += dp[i][j];
            if(dp[i][j+current] == INF) dp[i][j+current] = dp[i][j];
            else dp[i][j+current] += dp[i][j];
        }
    }

    printf("%lld", dp[n][n]);

    return 0;
}

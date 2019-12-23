#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N, M, arr[1010][1010], dp[1010][1010];

int main(){
    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf(" %d", &arr[i][j]);
        }
    }

    dp[1][1] = arr[1][1];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + arr[i][j+1]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]);
        }
    }

    printf("%d", dp[N][M]);

    return 0;
}

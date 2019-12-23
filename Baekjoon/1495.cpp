#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, S, M, maxx = -1;
int arr[110];
int dp[110][1010];
int INF = 1e9;

int main(){
    scanf("%d %d %d", &N, &S, &M);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    memset(dp, 0, sizeof(dp));
    dp[0][S] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            if(dp[i][j]){
                if(j + arr[i+1] <= M) dp[i+1][j+arr[i+1]] = 1;
                if(j - arr[i+1] >= 0) dp[i+1][j-arr[i+1]] = 1;
            }
        }
    }

    for(int i=0; i<=M; i++){
        if(dp[N][i]) maxx = max(maxx, i);
    }

    if(maxx != -1) printf("%d", maxx);
    else printf("-1");

    return 0;
}

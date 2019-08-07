#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N, maxx;
int dp[1010], val[1010];

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &val[i]);
    }

    dp[0] = val[0];
    maxx = val[0];

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(val[i] > val[j]) dp[i] = max(dp[i], dp[j] + val[i]);
            else dp[i] = max(dp[i], val[i]);
            maxx = max(maxx, dp[i]);
        }
    }

    printf("%d", maxx);

    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int N, arr[100010], dp[100010];

int main(){
    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        scanf(" %d", &arr[i]);
    }

    int maxx = arr[0];
    dp[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        if(dp[i-1] + arr[i] > arr[i]){
            dp[i] = dp[i - 1] + arr[i];
        }
        else
            dp[i] = arr[i];

        maxx = max(maxx, dp[i]);
    }

    printf("%d", maxx);

    return 0;
}
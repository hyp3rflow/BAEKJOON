#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N;
int INF = 1e9;
int arr[1200], dp[1200];

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    for(int i=0; i<1200; i++) dp[i] = INF;
    dp[0] = 0;

    for(int i=0; i<N; i++){
        int current = arr[i];
        for(int j=1; j<=current; j++){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }

    if(dp[N-1] == INF){
        printf("-1");
    }
    else{
        printf("%d", dp[N-1]);
    }

    return 0;
}

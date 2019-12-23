#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int T, n;
int INF = 1e9;


int main(){
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        int arr[4][100010] = {0};
        int dp[4][100010] = {0};
        scanf("%d", &n);

        for(int j=1; j<3; j++){
            for(int k=1; k<n+1; k++){
                scanf(" %d", &arr[j][k]);
            }
        }

        for(int k=1; k<n+1; k++){
            for(int j=1; j<=3; j++){
                int maxx = 0;
                for(int l=1; l<=3; l++){
                    if(l==j) continue;
                    maxx = max(maxx, dp[l][k-1]);
                }
                dp[j][k] = maxx + arr[j][k];
            }
        }

        int res = 0;
        for(int k=1; k<=3; k++){
            res = max(res, dp[k][n]);
        }

        printf("%d\n", res);
    }

    return 0;
}

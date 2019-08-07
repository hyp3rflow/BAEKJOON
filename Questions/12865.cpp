#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N, K, W, V, maxx;
typedef pair<int, int> p;
vector<p> v;
int dp[110][100010];

int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d %d", &W, &V);
        v.push_back(make_pair(W, V));
    }

    sort(v.begin(), v.begin()+N);

    for(int i=1; i<=N; i++){
        int weight = v[i-1].first;
        int value = v[i-1].second;

        for(int j=0; j<=K; j++){
            if(j >= weight) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight] + value);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int i=1; i<=K; i++){
        maxx = max(maxx, dp[N][i]);
    }
    printf("%d", maxx);

    return 0;
}

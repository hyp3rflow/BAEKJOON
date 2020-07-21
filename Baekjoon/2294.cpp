#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const ll MOD = 1e9 + 7;
const int stMAX = 1 << 18;
const int INF = 1e9;
int N, K, dp[110][10010];
int cost[110];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 10010; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        cost[i] = tmp;
    }

    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
        for (int j = 0; j <= K; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j + cost[i] <= K)
                dp[i][j + cost[i]] = min(dp[i][j + cost[i]], dp[i][j] + 1);
        }
    }

    int result;
    if (dp[N - 1][K] == INF)
        result = -1;
    else
        result = dp[N - 1][K];
    cout << result;
}
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
int N, dp[1010], p[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> p[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + p[j]);
        }
    }

    cout << dp[N];
}
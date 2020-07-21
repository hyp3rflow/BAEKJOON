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
int N, dp[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i < 1010; i++) {
        dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] * 2) % 10007) % 10007;
    }

    cout << dp[N] % 10007;
}
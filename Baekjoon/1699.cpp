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
int N, powed[400], dp[100010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 400; i++) {
        powed[i] = i * i;
    }

    cin >> N;

    for (int i = 1; i < 100000; i++) {
        dp[i] = i;
        for (int j = 1; powed[j] <= i; j++) {
            dp[i] = min(dp[i], dp[i - powed[j]] + 1);
        }
    }

    cout << dp[N];
}
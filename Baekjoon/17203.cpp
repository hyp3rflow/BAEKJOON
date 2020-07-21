#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define fup(i, a, b, c) for (int(i) = (a); (i) <= (b); (i) += (c))
#define fdn(i, a, b, c) for (int(i) = (a); (i) >= (b); (i) -= (c))
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
ll N, Q, a, arr[1010], dp[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    fup(i, 1, N, 1) {
        cin >> arr[i];
    }

    fup(i, 2, N, 1) {
        dp[i] = abs(arr[i] - arr[i - 1]) + dp[i - 1];
    }

    fup(i, 1, Q, 1) {
        int q, w;
        cin >> q >> w;
        if (q > w)
            swap(q, w);
        if (q == w)
            cout << 0 << endl;
        else
            cout << dp[w] - dp[q] << endl;
    }
}
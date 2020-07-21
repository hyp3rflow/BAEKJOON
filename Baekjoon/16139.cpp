#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
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
int N, Q, q[200010], l, r, dp[200010][30];
string S;
char a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    cin >> Q;

    int length = S.length();
    fup(i, 0, length - 1, 1) {
        fup(j, 'a', 'z', 1) {
            if (S[i] == j)
                dp[i + 1][j - 'a']++;
            dp[i + 1][j - 'a'] += dp[i][j - 'a'];
        }
    }

    fup(i, 1, Q, 1) {
        cin >> a >> l >> r;
        if (l == r && a == S[i - 1])
            cout << 1 << endl;
        else
            cout << dp[r + 1][a - 'a'] - dp[l][a - 'a'] << endl;
    }
}
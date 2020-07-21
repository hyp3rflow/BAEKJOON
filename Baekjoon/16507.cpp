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
int N, R, C, Q, arr[1010][1010], sum[1010][1010], K;

int r1, c1, r2, c2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> Q;

    fup(i, 1, R, 1) {
        fup(j, 1, C, 1) {
            cin >> arr[i][j];
            sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    fup(i, 1, Q, 1) {
        cin >> r1 >> c1 >> r2 >> c2;
        int width = r2 - r1;
        int height = c2 - c1;

        int ans = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];

        ans /= (width + 1) * (height + 1);

        cout << ans << endl;
    }
}
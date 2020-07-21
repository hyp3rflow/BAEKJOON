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
int N, M, a[100010], q, w;
ll psum[100010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    fup(i, 1, N, 1) {
        cin >> a[i];
    }

    psum[1] = a[1];
    fup(i, 2, N, 1) {
        psum[i] = psum[i - 1] + a[i];
    }

    cin >> M;
    fup(i, 1, M, 1) {
        cin >> q >> w;
        cout << psum[w] - psum[q - 1] << endl;
    }
}
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
int N, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k;

    int l = 1, r = 1e9;
    while (l <= r) {
        int mid = l + r >> 1;

        ll cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l;
}
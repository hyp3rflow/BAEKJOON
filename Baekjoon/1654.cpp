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
typedef vector<ll> vl;
typedef vector<pi> vii;
const ll MOD = 1e9 + 7;
const int stMAX = 1 << 18;
const int INF = 1e9;
int N, K, length;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    vl v;
    for (int i = 0; i < K; i++) {
        cin >> length;
        v.emplace_back(length);
    }

    ll l = 0, r = INT32_MAX;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll cnt = 0;
        for (ll p : v) {
            cnt += p / mid;
        }

        if (cnt >= N) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << l - 1;
}
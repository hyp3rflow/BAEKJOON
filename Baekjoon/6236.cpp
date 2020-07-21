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
int N, M, K, money;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vi v;
    for (int i = 0; i < N; i++) {
        cin >> money;
        v.emplace_back(money);
    }

    int l = 0, r = 1'000'000'000;
    while (l <= r) {
        int m = l + r >> 1;

        int cnt = 1, curr = m;
        int flag = 0;
        for (int p : v) {
            if (p > m) {
                flag = 1;
                break;
            }
            if (curr - p < 0) {
                cnt++;
                curr = m;
            }
            curr -= p;
        }

        if (cnt > M || flag) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    cout << l;
}
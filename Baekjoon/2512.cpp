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
int N, M, budget;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vi v;
    for (int i = 0; i < N; i++) {
        cin >> budget;
        v.emplace_back(budget);
    }

    cin >> M;

    sort(v.begin(), v.end());

    ll tmp = M;
    for (int p : v) {
        tmp -= p;
    }

    if (tmp >= 0) {
        cout << v.back();
        return 0;
    }

    int l = 0, h = M;
    while (l <= h) {
        int m = l + h >> 1;
        ll tmp = M;

        for (int p : v) {
            if (p <= m)
                tmp -= p;
            else {
                tmp -= m;
            }
        }

        if (tmp >= 0) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << l - 1;
}
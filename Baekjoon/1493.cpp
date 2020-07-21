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
const ll MOD = 1e9 + 7;
const int stMAX = 1 << 18;
const int INF = 1e9;
ll N, l, w, h;

vector<pl> p;

int main() {
    cin >> l >> w >> h >> N;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;

        p.emplace_back(a, b);
    }

    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    ll checker = 0, result = 0, tmp = 0;
    for (auto &v : p) {
        checker *= 1 << 3;
        ll tmp = min(v.second, (l >> v.first) * (w >> v.first) * (h >> v.first) - checker);
        checker += tmp;
        result += tmp;
    }

    cout << (l * w * h == checker ? result : -1);
}
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
int N, M, height;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vi tree;

    for (int i = 0; i < N; i++) {
        cin >> height;
        tree.emplace_back(height);
    }

    int l = 0, h = 1'000'000'000;

    // binary search
    while (l <= h) {
        int m = l + h >> 1;

        ll sum = 0;
        for (int p : tree) {
            if (p > m)
                sum += p - m;
        }

        if (sum >= M) {
            l = m + 1;
        } else
            h = m - 1;
    }

    cout << l - 1;
}
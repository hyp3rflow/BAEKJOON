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
int N, M, minute;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    vi v;
    int maxx = 0;
    for (int i = 0; i < N; i++) {
        cin >> minute;
        v.emplace_back(minute);

        // 이거 안써서 틀렸네 ㅋㅋ
        maxx = max(minute, maxx);
    }

    int l = maxx, h = 1'000'000'000;
    while (l <= h) {
        int m = l + h >> 1;

        int cnt = 1, sum = 0;
        for (int p : v) {
            if (sum + p > m) {
                cnt++;
                sum = 0;
            }
            sum += p;
        }

        if (cnt > M) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << l;
}

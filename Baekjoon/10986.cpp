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
ll N, M, arr[(int)1e6 + 10], sum[(int)1e6 + 10], cnt[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fup(i, 1, N, 1) {
        cin >> arr[i];
        sum[i] = (sum[i - 1] % M + arr[i] % M) % M;

        cnt[sum[i]]++;
    }

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
ll N, M, arr[(int)1e6 + 10], sum[(int)1e6 + 10], cnt[1010];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fup(i, 1, N, 1) {
        cin >> arr[i];
        sum[i] = (sum[i - 1] % M + arr[i] % M) % M;

        cnt[sum[i]]++;
    }

    // sum[j] - sum[i-1] % M = 0 -> sum[j] % M = sum[i-1] % M
    // 순서쌍 찾기이므로 개수 C 2

    ll ans = cnt[0];
    fup(i, 0, M - 1, 1) {
        ll curr = cnt[i];
        ans += curr * (curr - 1) / 2;
    }

    cout << ans;
}

    ll ans = cnt[0];
    fup(i, 0, M - 1, 1) {
        ll curr = cnt[i];
        ans += curr * (curr - 1) / 2;
    }

    cout << ans;
}
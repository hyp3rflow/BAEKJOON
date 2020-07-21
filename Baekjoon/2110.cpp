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
int N, C, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    vi v;
    for (int i = 0; i < N; i++) {
        cin >> x;
        v.emplace_back(x);
    }

    sort(v.begin(), v.end());

    int l = 1, r = 1'000'000'000;
    while (l <= r) {
        int length = l + r >> 1;

        int size = v.size();
        int cnt = 0;
        for (int i = 0; i < size;) {
            int curr = v[i];
            int next = -1;
            cnt++;
            for (int j = i + 1; j < size; j++) {
                if (v[j] - curr >= length) {
                    next = j;
                    break;
                }
            }

            if (next != -1) {
                i = next;
            } else {
                break;
            }
        }

        if (cnt >= C) {
            l = length + 1;
        } else {
            r = length - 1;
        }
    }

    cout << l - 1;
}
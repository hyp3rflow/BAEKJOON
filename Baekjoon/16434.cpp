#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define endl "\n"

using namespace std;

typedef struct Room {
    Room(int t, int a, int h) : t(t), a(a), h(h) {}
    int t, a, h;
} room;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const ll MOD = 1e9 + 7;
const int stMAX = 1 << 18;
const int INF = 1e9;
int N, H, t, a, h;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;

    vector<Room> v;

    for (int i = 0; i < N; i++) {
        cin >> t >> a >> h;
        v.emplace_back(t, a, h);
    }

    ll l = 1, r = 1e18;
    while (l <= r) {
        ll mid = l + r >> 1;

        ll curr_hp = mid, curr_atk = H, flag = 0;
        for (auto &p : v) {
            if (p.t == 1) {
                if ((p.h - 1) / curr_atk > (curr_hp - 1) / p.a) {
                    flag = 1;
                    break;
                }
                curr_hp -= (p.h - 1) / curr_atk * p.a;

            } else {
                curr_hp = curr_hp + p.h > mid ? mid : curr_hp + p.h;
                curr_atk += p.a;
            }
        }

        if (flag == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l;
}
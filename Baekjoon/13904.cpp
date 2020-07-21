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
int N, arr[1010];
pair<int, int> p[1010];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + N, [](pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    });

    int result = 0;

    for (int i = 0; i < N; i++) {
        for (int j = p[i].first; j > 0; j--) {
            if (!arr[j]) {
                arr[j] = 1;
                result += p[i].second;
                break;
            }
        }
    }

    cout << result;
}
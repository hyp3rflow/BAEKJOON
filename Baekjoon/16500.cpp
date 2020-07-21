#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
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
int N, dp[110];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cin >> N;

    vector<string> v;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        v.emplace_back(tmp);
    }

    dp[s.length()]++;

    int length = s.length();

    for (int i = length - 1; i >= 0; i--) {
        int size = v.size();
        for (int j = 0; j < size; j++) {
            if (s.find(v[j], i) == i && dp[i + v[j].length()]) {
                dp[i] = 1;
                break;
            } else {
                dp[i] = 0;
            }
        }
    }

    cout << dp[0];
}
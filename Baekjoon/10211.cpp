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
int N, T, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    fup(_, 1, T, 1) {
        cin >> N;

        int arr[1010] = {0}, sum[1010] = {0};

        fup(i, 1, N, 1) {
            cin >> arr[i];
            sum[i] = sum[i - 1] + arr[i];
        }
        
        // 문제를 제대로 안보고 0으로 초기화하면 틀린다.
        int result = -INF;
        fup(i, 1, N, 1) {
            fup(j, i, N, 1) {
                if (i == j)
                    result = max(result, arr[i]);
                else
                    result = max(result, sum[j] - sum[i - 1]);
            }
        }

        cout << result << endl;
    }
}
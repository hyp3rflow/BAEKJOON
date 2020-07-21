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
int N, arr[100010];
int K;
vector<int> v;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 1; i < N; i++) {
        v.push_back(arr[i] - arr[i - 1]);
    }

    sort(v.begin(), v.end());

    int result = arr[N - 1] - arr[0];
    for (int i = 0; i < K - 1; i++) {
        // 저격 TC가 있는 듯
        if (v.empty())
            break;
        result -= v.back();
        v.pop_back();
    }

    cout << result;
}
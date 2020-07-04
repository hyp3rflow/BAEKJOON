#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1e5 + 10;
typedef long long ll;

int N, M, a[MAX], b[MAX], c[MAX], p[MAX];
int range[MAX];

int main() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> p[i];
    }

    for (int i = 2; i <= M; i++) {
        int prev = p[i - 1];
        int next = p[i];

        if (prev > next)
            swap(prev, next);
        range[prev]++;
        range[next]--;
    }

    for (int i = 1; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    ll result = 0, sum = 0;
    for (int i = 1; i < N; i++) {
        sum += range[i];
        result += min(sum * a[i], sum * b[i] + c[i]);
    }

    cout << result;
}
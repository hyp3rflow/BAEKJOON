#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll N, result, jump, nn;

ll solve() {
    ll limit = sqrt(N);
    for (ll i = 1; i <= limit; i++) {
        result += ceil((double)N / i);
    }

    for (ll i = limit + 1; i <= N; i = nn + 1) {
        if (i == N) {
            result += 1;
            break;
        }
        jump = ceil((double)N / i);
        nn = ceil((double)N / (jump - 1)) - 1;
        result += (nn - i + 1) * jump;
    }

    return result;
}

int main() {
    cin >> N;
    cout << solve();
}
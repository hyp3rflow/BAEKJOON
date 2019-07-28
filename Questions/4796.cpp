#include <iostream>
#include <algorithm>

using namespace std;

int L, P, V, cnt = 1, res;

int main() {
    while (1) {
        cin >> L >> P >> V;
        res = 0;

        if (L == 0) break;
        else {
            while (V > 0) {
                if (V >= L) res += L;
                else res += V;
                V -= P;
            }

            cout << "Case " << cnt++ << ": " << res << endl;
        }
    }

    return 0;
}
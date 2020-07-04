#include <algorithm>
#include <iostream>

using namespace std;

int m, f, q, n, x;

const int MAX = 5e5 + 10;
const int MAX_D = 19;

int sparse[MAX][MAX_D];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> sparse[i][0];
    }

    for (int i = 1; i < MAX_D; i++) {
        for (int j = 1; j <= m; j++) {
            // 2^(n+1) = 2 * 2^n = 2^n + 2^n
            sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> x;
        for (int j = MAX_D - 1; j >= 0; j--) {
            if (n & 1 << j) {
                n ^= 1 << j;
                x = sparse[x][j];
            }
        }

        cout << x << "\n";
    }
}
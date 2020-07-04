#include <algorithm>
#include <iostream>

using namespace std;

int N, K, M;

typedef long long ll;

const int MAX = 1e5 + 10;
const int MAX_D = 31;

int youtube[MAX][MAX_D];
int student[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;

    for (int i = 1; i <= N; i++) {
        cin >> student[i];
    }

    for (int i = 1; i <= K; i++) {
        cin >> youtube[i][0];
    }

    for (int j = 1; j < MAX_D; j++) {
        for (int i = 1; i <= K; i++) {
            youtube[i][j] = youtube[youtube[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= N; i++) {
        ll tmp = M - 1;
        for (ll j = MAX_D - 1; j >= 0; j--) {
            if (tmp & 1 << j) {
                tmp ^= 1 << j;
                student[i] = youtube[student[i]][j];
            }
        }

        cout << student[i] << " ";
    }
}
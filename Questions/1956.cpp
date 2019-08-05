#include <iostream>

using namespace std;

int INF = 1e9;
int V, E, a, b, c, arr[410][410], minn = INF, cnt;

int main() {
    scanf("%d %d", &V, &E);
    for (int i = 0; i < 410; i++) {
        for (int j = 0; j < 410; j++) arr[i][j] = INF;
    }
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &c);
        arr[a][b] = c;
    }

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            for (int k = 1; k <= V; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (minn > arr[i][i]) {
            minn = arr[i][i];
        }
    }

    if (minn >= INF) printf("-1");
    else printf("%d", minn);
    return 0;
}
    

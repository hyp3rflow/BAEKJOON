#include <iostream>
#include <algorithm>

using namespace std;

int INF = 1e9;
int N, M, a, b, arr[110][110];

int main(){
    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++){
            arr[i][j] = INF;
            arr[j][j] = 0;
        }
    }

    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(arr[i][j] != INF || arr[j][i] != INF);
            else cnt++;
        }
        printf("%d\n", cnt);
    }

    return 0;
}

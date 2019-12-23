#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int INF = 1e9;
int N, M, a, b, minn = INF, res;
int v[110][110];

int main(){
    scanf("%d %d", &N, &M);

    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++){
            v[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++){
        scanf("%d %d", &a, &b);
        v[a][b] = 1;
        v[b][a] = 1;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(i != j) cnt += v[i][j];
        }
        if(minn > cnt){
            res = i;
            minn = cnt;
        }
    }

    printf("%d", res);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>


using namespace std;

int INF = 10000000;
int N, a, b, minscore[51], res = INF, cnt;
int adj[51][51];
bool flag;

int main(){
    scanf("%d", &N);
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            adj[i][j] = INF;
            adj[j][j] = 0;
        }
    }

    while(1){
        scanf("%d %d", &a, &b);
        if(a == -1 && b == -1) break;
        else{
            adj[a][b] = 1;
            adj[b][a] = 1;
            minscore[a] = 1;
            minscore[b] = 1;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                if(adj[j][k] > adj[j][i] + adj[i][k]){
                    adj[j][k] = adj[j][i] + adj[i][k];
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][j] == INF) continue;
            minscore[i] = max(minscore[i], adj[i][j]);
        }
    }

    for(int i=1; i<=N; i++){
        if(minscore[i] == 0) flag = true;
        res = min(res, minscore[i]);
    }

    for(int i=1; i<=N; i++){
        if(minscore[i] == res){
            cnt++;
        }
    }

    if(flag){
        res = 0;
        cnt = 0;
    }

    printf("%d %d\n", res, cnt);

    for(int i=1; i<=N; i++){
        if(minscore[i] == res){
            printf("%d ", i);
        }
    }

    return 0;
}

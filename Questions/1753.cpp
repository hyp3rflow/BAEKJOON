#include <stdio.h>
#include <vector>
#include <queue>
#define mk make_pair
#define MAXN 300010
#define MAX 1000000000

using namespace std;

int D[MAXN+1];
bool chk[MAXN+1];

vector<pair<int, int>> edge[MAXN+1];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    int n, m, i, a, b, d, s;

    scanf("%d %d", &n, &m);
    scanf("%d", &s);
    for(i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &d);
        edge[a].push_back(mk(b,d));
    }

    for(i=0; i<MAXN+1; i++) D[i] = MAX;

    D[s] = 0;
    pq.push(mk(0, s));
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        if(chk[v]) continue;
        chk[v] = true;

        for(i=0; i<edge[v].size(); i++){
            int u = edge[v][i].first;
            int d = edge[v][i].second;

            if(D[u] > D[v] + d){
                D[u] = D[v] + d;
                pq.push(mk(D[u], u));
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if (D[i] == MAX) {
            printf("INF\n");
        continue;
    }
        printf("%d\n", D[i]);
    }

    return 0;
}

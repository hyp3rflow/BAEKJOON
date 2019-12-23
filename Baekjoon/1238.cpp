#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> p;

int INF = 1e9;
int N, M, X, s, e, t, res, D[1010][1010];;
priority_queue<p, vector<p>, greater<p>> pq[1010];
vector<p> v[1010];

int main() {
    scanf("%d %d %d", &N, &M, &X);
    for(int i=1; i<=M; i++){
        scanf("%d %d %d", &s, &e, &t);
        v[s].push_back(make_pair(e, t));
    }

    for(int i=1; i<=N; i++){
        pq[i].push(make_pair(0, i));
        bool chk[1010] = {0};
        for(int j=0; j<=N; j++) D[i][j] = INF;

        D[i][i] = 0;

        while(!pq[i].empty()){
            int u = pq[i].top().second;
            pq[i].pop();

            if(chk[u]) continue;
            chk[u] = true;

            for(int j=0; j<v[u].size(); j++){
                int w = v[u][j].first;
                int d = v[u][j].second;

                if(D[i][w] > D[i][u] + d){
                    D[i][w] = D[i][u] + d;
                    pq[i].push(make_pair(D[i][w], w));
                }
            }
        }
    }

    for(int i=1; i<=N; i++){
        res = max(res, D[i][X] + D[X][i]);
    }

    printf("%d", res);

    return 0;
}

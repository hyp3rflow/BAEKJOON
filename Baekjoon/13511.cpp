#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>

#define mk make_pair

using namespace std;

typedef long long ll;
typedef pair<char, char> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;


int N, M, T, K, Q;

const int MAX = 100000;
const int MAXN = 20;
int d[MAX + 10], visited[MAX + 10], par[MAX + 10][MAXN];

vector<int> inf[100010];
vector<pair<double, p>> arr;
stack<int> s;
queue<int> q;

void dfs(int current){
    for(int next: inf[current]){
        if(!d[next]){
            d[next] = d[current] + 1;
            par[next][0] = current;
            dfs(next);
        }
    }
}

int LCA(int x, int y){
    if(d[x] < d[y]) swap(x, y);

    if(x == y) return x;

    int diff = d[x] - d[y];

    for(int k=0; diff; k++){
        if(diff % 2) x = par[x][k];
        diff /= 2;
    }

    if(x != y){
        for(int k=MAXN-1; k>=0; k--){
            if(par[x][k] != -1 && par[x][k] != par[y][k]){
                x = par[x][k];
                y = par[y][k];
            }
        }

        x = par[x][0];
    }

    return x;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        inf[x].push_back(y);
        inf[y].push_back(x);
    }

    memset(par, -1, sizeof(par));

    d[1] = 1;
    dfs(1);

    for(int j=0; j<MAXN-1; j++){
        for(int i=1; i<=N; i++){
            if(par[i][j] != -1) par[i][j+1] = par[par[i][j]][j];
        }
    }

    int m;

    scanf("%d", &m);

    int ret, t;
    for (int u ,v ,r, i = 0; i < m; i++) {
        scanf("%d %d %d", &r, &u, &v);
        ret = LCA(r, u);
        t = LCA(u, v);
        ret = d[ret] > d[t] ? ret : t;
        t = LCA(r, v);
        ret = d[ret] > d[t] ? ret : t;
        printf("%d\n", ret);
    }

    return 0;
}

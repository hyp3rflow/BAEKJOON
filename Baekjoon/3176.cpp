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
typedef pair<int, int> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;

int N, M, T, K, Q;

const int INF = 1e9;
const int MAX = 1e5;
const int MAXN = 20;
int d[MAX + 10], visited[MAX + 10], par[MAX + 10][MAXN];
int distmin[MAX + 10][MAXN], distmax[MAX + 10][MAXN];

vector<p> inf[100010];
vector<pair<double, p>> arr;
stack<int> s;
queue<int> q;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y, dist;
        scanf("%d %d %d", &x, &y, &dist);

        x--; y--;
        inf[x].push_back(mk(y, dist));
        inf[y].push_back(mk(x, dist));
    }

    memset(par, -1, sizeof(par));
    memset(d, -1, sizeof(d));

    s.push(0);
    d[0] = 0;
    distmin[0][0] = 0;
    distmax[0][0] = 0;
    while(!s.empty()){
        int current = s.top();
        s.pop();

        for(p next: inf[current]){
            if(d[next.first] == -1){
                par[next.first][0] = current;
                d[next.first] = d[current] + 1;
                distmin[next.first][0] = next.second;
                distmax[next.first][0] = next.second;
                s.push(next.first);
            }
        }
    }

    for(int j=1; j<MAXN; j++){
        for(int i=0; i<N; i++){
            par[i][j] = par[par[i][j-1]][j-1];
            distmin[i][j] = min(distmin[i][j-1], distmin[par[i][j-1]][j-1]);
            distmax[i][j] = max(distmax[i][j-1], distmax[par[i][j-1]][j-1]);
        }
    }

    scanf("%d", &M);
    for(int j=0; j<M; j++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;

        int minn = INF;
        int maxx = -1 * INF;

        if(d[x] < d[y]) swap(x, y);
        int diff = d[x] - d[y];

        for(int k=0; diff; k++){
            if(diff % 2){
                minn = min(minn, distmin[x][k]);
                maxx = max(maxx, distmax[x][k]);
                x = par[x][k];
            }
            diff /= 2;
        }

        if(x != y){
            for(int k=MAXN-1; k>=0; k--){
                if(par[x][k] != -1 && par[x][k] != par[y][k]){
                    minn = min(minn, min(distmin[x][k], distmin[y][k]));
                    maxx = max(maxx, max(distmax[x][k], distmax[y][k]));
                    x = par[x][k];
                    y = par[y][k];
                }
            }

            minn = min(minn, min(distmin[x][0], distmin[y][0]));
            maxx = max(maxx, max(distmax[x][0], distmax[y][0]));
        }

        printf("%d %d\n", minn, maxx);
    }

    return 0;
}


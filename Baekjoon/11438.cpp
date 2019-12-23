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

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        x--; y--;
        inf[x].push_back(y);
        inf[y].push_back(x);
    }

    memset(par, -1, sizeof(par));
    memset(d, -1, sizeof(d));

    s.push(0);
    d[0] = 0;
    while(!s.empty()){
        int current = s.top();
        s.pop();

        for(int next: inf[current]){
            if(d[next] == -1){
                par[next][0] = current;
                d[next] = d[current] + 1;
                s.push(next);
            }
        }
    }

    for(int j=0; j<MAXN-1; j++){
        for(int i=1; i<N; i++){
            if(par[i][j] != -1) par[i][j+1] = par[par[i][j]][j];
        }
    }

    scanf("%d", &M);
    for(int j=0; j<M; j++){
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;

        if(d[x] < d[y]) swap(x, y);
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

        printf("%d\n", x+1);
    }

    return 0;
}

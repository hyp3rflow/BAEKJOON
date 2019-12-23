#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>

#define mk make_pair

using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;
int N, M, a, b, c;
vector<ip> edge;

int uf[1000010];
int find(int a){ //union-find fill(-1) needed
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    uf[b] = a;
    return true;
}

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a, &b, &c);
        edge.push_back(mk(c, mk(a, b)));
    }

    sort(edge.begin(), edge.begin()+M);

    int result = 0, cnt =0;
    fill(uf, uf+N, -1);
    for(int i=0; ;i++){
        if(uni(edge[i].second.first, edge[i].second.second)){
            result += edge[i].first;
            if(++cnt == N-2) break;
        }
    }

    printf("%d\n", result);

    return 0;
}

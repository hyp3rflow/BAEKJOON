#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

#define mk make_pair

using namespace std;

typedef pair<char, char> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;
int N, M, T;
vector<int> inf[100010];
vector<pair<double, p>> arr;
stack<int> s;
queue<int> q;
int parent[100010];
int visited[100010];

int main() {
    scanf("%d", &N);

    for(int i=0; i<N-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        inf[a].push_back(b);
        inf[b].push_back(a);
    }

    s.push(1);
    while (!s.empty()){
        int current = s.top();
        visited[current] = true;
        s.pop();

        for(int i=0; i<inf[current].size(); i++){
            int next = inf[current][i];
            if(!visited[next]) {
                parent[next] = current;
                s.push(next);
            }
        }
    }

    for(int i=2; i<=N; i++) printf("%d\n", parent[i]);

    return 0;
}


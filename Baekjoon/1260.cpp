#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N, M, V;
stack<int> dfs;
queue<int> bfs;

int main(){
    cin >> N >> M >> V;

    vector<int> graph[N+1];
    bool check[N+1];
    fill(check, check+N+1, false);

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int j=1; j<=N; j++) sort(graph[j].begin(), graph[j].end());


    dfs.push(V);
    bfs.push(V);

    check[V] = true;

    cout << V << " ";
    while(!dfs.empty()){
        int cnode = dfs.top();
        dfs.pop();
        for(int i=0; i<graph[cnode].size(); i++){
            int nextnode = graph[cnode][i];
            if(check[nextnode] == false){
                check[nextnode] = true;
                cout << nextnode << " ";
                dfs.push(cnode);
                dfs.push(nextnode);
                break;
            }
        }
    }

    cout << endl;

    fill(check, check+N+1, false);

    check[V] = true;
    while(!bfs.empty()){
        int cnode = bfs.front();
        bfs.pop();
        cout << cnode << " ";
        for(int i=0; i<graph[cnode].size(); i++){
            if(check[graph[cnode][i]] == false){
                bfs.push(graph[cnode][i]);
                check[graph[cnode][i]] = true;
            }
        }
    }
    
    return 0;
}

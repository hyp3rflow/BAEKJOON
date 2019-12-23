#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

int INF = 1e9;
int N, cnt = 1, res;
priority_queue<pp, vector<pp>, greater<pp>> pq;

int main(){
    while(1){
        scanf("%d", &N);
        if(!N) break;

        int arr[130][130] = {0};
        int d[130][130];
        bool visited[130][130] = {0};

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int tmp;
                scanf("%d ", &tmp);
                arr[i][j] = tmp;
                d[i][j] = INF;
            }
        }

        pq.push(make_pair(arr[0][0], make_pair(0, 0)));
        d[0][0] = arr[0][0];

        while(!pq.empty()){
            int vx = pq.top().second.first;
            int vy = pq.top().second.second;
            pq.pop();

            if(visited[vx][vy]) continue;
            visited[vx][vy] = true;

            if(vx > 0){
                int w = arr[vx-1][vy];

                if(d[vx-1][vy] > d[vx][vy] + w){
                    d[vx-1][vy] = d[vx][vy] + w;
                    pq.push(make_pair(d[vx-1][vy], make_pair(vx-1, vy)));
                }
            }
            if(vy > 0){
                int w = arr[vx][vy-1];

                if(d[vx][vy-1] > d[vx][vy] + w){
                    d[vx][vy-1] = d[vx][vy] + w;
                    pq.push(make_pair(d[vx][vy-1], make_pair(vx, vy-1)));
                }
            }
            if(vx < N-1){
                int w = arr[vx+1][vy];

                if(d[vx+1][vy] > d[vx][vy] + w){
                    d[vx+1][vy] = d[vx][vy] + w;
                    pq.push(make_pair(d[vx+1][vy], make_pair(vx+1, vy)));
                }
            }
            if(vy < N-1){
                int w = arr[vx][vy+1];

                if(d[vx][vy+1] > d[vx][vy] + w){
                    d[vx][vy+1] = d[vx][vy] + w;
                    pq.push(make_pair(d[vx][vy+1], make_pair(vx, vy+1)));
                }
            }
        }

        res = d[N-1][N-1];

        printf("Problem %d: ", cnt++);
        printf("%d\n", res);
    }

    return 0;
}

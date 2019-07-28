#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, arr[1010][1010], check[1010][1010], maxx;
queue<pair<pair<int, int>, int>> q;

int main(){
    cin >> M >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push(make_pair(make_pair(i, j), 0)), check[i][j] = 1;
            else if(arr[i][j] == -1) check[i][j] = 1;
        }
    }

    while(!q.empty()){
        int x, y, tmp;
        x = q.front().first.first;
        y = q.front().first.second;
        tmp = q.front().second;

        maxx = max(tmp, maxx);

        q.pop();

        if(x+1 <= N && check[x+1][y] != 1 && arr[x+1][y] == 0) q.push(make_pair(make_pair(x+1,y), tmp+1)), check[x+1][y] = 1;
        if(x-1 >= 1 && check[x-1][y] != 1 && arr[x-1][y] == 0) q.push(make_pair(make_pair(x-1,y), tmp+1)), check[x-1][y] = 1;
        if(y+1 <= M && check[x][y+1] != 1 && arr[x][y+1] == 0) q.push(make_pair(make_pair(x,y+1), tmp+1)), check[x][y+1] = 1;
        if(y-1 >= 1 && check[x][y-1] != 1 && arr[x][y-1] == 0) q.push(make_pair(make_pair(x,y-1), tmp+1)), check[x][y-1] = 1;
    }

    int flag = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(check[i][j] != 1) flag = 1;
        }
    }

    if(flag) cout << "-1";
    else cout << maxx;

    return 0;
}

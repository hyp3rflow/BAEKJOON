#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, H, arr[110][110][110], check[110][110][110], maxx;
queue<pair<pair<pair<int, int>, int>, int>> q;

int main(){
    cin >> M >> N >> H;
    for(int k=1; k<=H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> arr[i][j][k];
                if (arr[i][j][k] == 1) q.push(make_pair(make_pair(make_pair(i,j), k), 0)), check[i][j][k] = 1;
                else if (arr[i][j][k] == -1) check[i][j][k] = 1;
            }
        }
    }

    while(!q.empty()){
        int x, y, h, tmp;
        x = q.front().first.first.first;
        y = q.front().first.first.second;
        h = q.front().first.second;
        tmp = q.front().second;

        maxx = max(tmp, maxx);

        q.pop();

        if(x+1 <= N && check[x+1][y][h] != 1 && arr[x+1][y][h] == 0) q.push(make_pair(make_pair(make_pair(x+1,y), h), tmp+1)), check[x+1][y][h] = 1;
        if(x-1 >= 1 && check[x-1][y][h] != 1 && arr[x-1][y][h] == 0) q.push(make_pair(make_pair(make_pair(x-1,y), h), tmp+1)), check[x-1][y][h] = 1;
        if(y+1 <= M && check[x][y+1][h] != 1 && arr[x][y+1][h] == 0) q.push(make_pair(make_pair(make_pair(x,y+1), h), tmp+1)), check[x][y+1][h] = 1;
        if(y-1 >= 1 && check[x][y-1][h] != 1 && arr[x][y-1][h] == 0) q.push(make_pair(make_pair(make_pair(x,y-1), h), tmp+1)), check[x][y-1][h] = 1;
        if(h+1 <= H && check[x][y][h+1] != 1 && arr[x][y][h+1] == 0) q.push(make_pair(make_pair(make_pair(x,y), h+1), tmp+1)), check[x][y][h+1] = 1;
        if(h-1 >= 1 && check[x][y][h-1] != 1 && arr[x][y][h-1] == 0) q.push(make_pair(make_pair(make_pair(x,y), h-1), tmp+1)), check[x][y][h-1] = 1;
    }

    int flag = 0;
    for(int k=1; k<=H; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (check[i][j][k] != 1) flag = 1;
            }
        }
    }

    if(flag) cout << "-1";
    else cout << maxx;

    return 0;
}

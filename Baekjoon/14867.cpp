#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> p;
map<p, int> r;
queue<p> q;

int m, n, rm, rn, cnt = 1;


int main(){
    cin >> m >> n >> rm >> rn;

    p curr = {0, 0};
    q.push(curr);
    r[curr] = cnt++;

    while(!q.empty()) {
        curr = q.front();
        q.pop();

        p tmp[6];
        tmp[0] = {0, curr.second};
        tmp[1] = {curr.first, 0};
        tmp[2] = {0, curr.second + curr.first};
        tmp[3] = {curr.first + curr.second, 0};
        tmp[4] = {m, curr.second};
        tmp[5] = {curr.first, n};

        if(tmp[3].first > m) tmp[3].first = m;
        if(tmp[2].second > n) tmp[2].second = n;

        for(int i=0; i<6; i++){
            if(!r[tmp[i]]){
                r[curr] = min(cnt, r[curr]);
                q.push(curr);
            }
        }

        cnt++;
    }

    int ans = r[make_pair(rm, rn)];

    cout << ans - 1 << endl;

    return 0;
}

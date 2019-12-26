#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
queue<int> q;

int main(){
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++){
        q.push(i);
    }

    printf("<");

    int cnt = 1;
    while (!q.empty()){
        if (cnt == K){
            printf("%d%s", q.front(), q.size() == 1 ? ">" : ", ");
            q.pop();
            cnt = 1;
        } else {
            q.push(q.front());
            q.pop();
            cnt++;
        }
    }
}
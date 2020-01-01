#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> p;
const int INF = 1e9+7;

int N, res;
p line[100010];

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int a, b;
        scanf(" %d %d", &a, &b);

        line[i] = p(a, b);
    }

    sort(line, line+N);

    int lineMin = -INF;
    int lineMax = -INF;

    for(int i=0; i<N; i++){
        if(lineMax < line[i].first){
            res += lineMax - lineMin;
            lineMin = line[i].first;
            lineMax = line[i].second;
        }
        else{
            lineMax = max(lineMax, line[i].second);
        }
    }

    res += lineMax - lineMin;

    printf("%d", res);
}
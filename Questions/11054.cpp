#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int N, maxx;
int dpmax[1010], dpmin[1010], val[1010];

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &val[i]);
    }

    dpmax[0] = 1;
    dpmin[N-1] = 1;

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(val[i] > val[j]) dpmax[i] = max(dpmax[i], dpmax[j] + 1);
            else dpmax[i] = max(dpmax[i], 1);
        }
    }

    for(int i=N-2; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(val[i] > val[j]) dpmin[i] = max(dpmin[i], dpmin[j] + 1);
            else dpmin[i] = max(dpmin[i], 1);
        }
    }

    for(int i=0; i<N; i++) maxx = max(maxx, dpmax[i] + dpmin[i]);

    printf("%d", maxx-1);

    return 0;
}

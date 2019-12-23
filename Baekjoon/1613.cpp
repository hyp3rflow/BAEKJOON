#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int INF = 1e9;
int n, k, a, b, s;
int arr[410][410];

int main(){
    for(int i=0; i<410; i++){
        for(int j=0; j<410; j++){
            arr[i][j] = INF;
            arr[j][j] = 0;
        }
    }

    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    scanf("%d", &s);
    for(int i=0; i<s; i++){
        scanf("%d %d", &a, &b);
        if(arr[a][b] != INF) printf("-1\n");
        else if(arr[b][a] != INF) printf("1\n");
        else printf("0\n");
    }

    return 0;
}

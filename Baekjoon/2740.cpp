#include <cstdio>
#include <algorithm>

using namespace std;

int A[110][110], B[110][110], res[110][110];
int N, M, K;

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf(" %d", &A[i][j]);
        }
    }

    scanf(" %d %d", &M, &K);
    for(int i=0; i<M; i++){
        for(int j=0; j<K; j++){
            scanf(" %d", &B[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            for(int k=0; k<M; k++){
                res[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
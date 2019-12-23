#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

#define mk make_pair

using namespace std;

typedef pair<char, char> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;
int N, M, T;
vector<p> inf[27];
vector<pair<double, p>> arr;
int pre[1010];
int in[1010];

void make_tree(int s1, int s2, int e1, int e2){
    if(s1 > s2) return;

    int left = 0;
    for(int i=e1; i<=e2; i++){
        if(in[i] == pre[s1]) break;
        left++;
    }

    make_tree(s1 + 1, s1 + left, e1, e1 + left - 1);
    make_tree(s1 + left + 1, s2, e1 + left + 1, e2);

    printf("%d ", pre[s1]);
}

int main() {
    scanf("%d", &T);

    for(int i=0; i<T; i++){
        scanf("%d", &N);

        for(int k=1; k<=N; k++){
            scanf("%d", &pre[k]);
        }

        for(int k=1; k<=N; k++){
            scanf("%d", &in[k]);
        }

        make_tree(1, N, 1, N);
        printf("\n");
    }

    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, M, p, q;
vector<int> arr;
vector<int> tree;

int init(int node, int l, int r){
    if(l == r)
        return tree[node] = arr[l];
    else
        return tree[node] = init(node * 2, l, (l + r) / 2) + init(node * 2 + 1, (l + r) / 2 + 1, r);
}

int sum(int node, int l, int r, int a, int b){
    if(r < a || b < l)
        return 0;
    if (a <= l && r <= b)
        return tree[node];
    return sum(node * 2, l, (l + r) / 2, a, b) + sum(node * 2 + 1, (l + r) / 2 + 1, r, a, b);
}

int main(){
    scanf("%d %d", &N, &M);

    arr = vector<int>(N + 1);
    tree = vector<int>(N * 4);

    for (int i = 1; i <= N; i++){
        scanf("%d", &arr[i]);
    }

    init(1, 1, N);

    for (int i = 0; i < M; i++){
        scanf("%d %d", &p, &q);
        printf("%d\n", sum(1, 1, N, p, q));
    }
}
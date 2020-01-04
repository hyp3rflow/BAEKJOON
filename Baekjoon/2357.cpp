#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;
int N, M, a, b;
const int INF = 1e9 + 7;

vector<int> arr;
vector<p> tree;

//first = min, second = max

p init(int node, int l, int r)
{
    if (l == r)
    {
        return tree[node] = p(arr[l], arr[l]);
    }
    else
    {
        p f = init(node * 2, l, (l + r) / 2);
        p s = init(node * 2 + 1, (l + r) / 2 + 1, r);
        return tree[node] = p(min(f.first, s.first), max(f.second, s.second));
    }
}

p sum(int node, int l, int r, int a, int b)
{
    if (b < l || r < a)
        return p(INF, -INF);
    if (a <= l && r <= b)
        return tree[node];
    p f = sum(node * 2, l, (l + r) / 2, a, b);
    p s = sum(node * 2 + 1, (l + r) / 2 + 1, r, a, b);
    return p(min(f.first, s.first), max(f.second, s.second));
}

int main()
{
    scanf("%d %d", &N, &M);

    arr = vector<int>(N + 1);
    tree = vector<p>(N * 4);

    for (int i = 0; i < N * 4; i++)
    {
        tree[i] = p(INF, -INF);
    }

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }

    init(1, 1, N);

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        p tmp = sum(1, 1, N, a, b);
        printf("%d %d\n", tmp.first, tmp.second);
    }
}
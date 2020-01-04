#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
int N, M, K, a, b, c;
vector<ll> arr, tree;

ll init(int node, int l, int r)
{
    if (l == r)
        return tree[node] = arr[l];
    else
        return tree[node] = ((init(node * 2, l, (l + r) / 2) % mod) * (init(node * 2 + 1, (l + r) / 2 + 1, r) % mod)) % mod;
}

ll update(int node, int l, int r, int idx, int value)
{
    if (idx < l || r < idx)
    {
        return tree[node];
    }
    if (l == r)
    {
        return tree[node] = value;
    }
    return tree[node] = ((update(node * 2, l, (l + r) / 2, idx, value) % mod) * (update(node * 2 + 1, (l + r) / 2 + 1, r, idx, value) % mod)) % mod;
}

ll sum(int node, int l, int r, int a, int b)
{
    if (b < l || r < a)
    {
        return 1;
    }
    if (a <= l && r <= b)
    {
        return tree[node];
    }
    return ((sum(node * 2, l, (l + r) / 2, a, b) % mod) * (sum(node * 2 + 1, (l + r) / 2 + 1, r, a, b) % mod)) % mod;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    arr = vector<ll>(N + 1);
    tree = vector<ll>(N * 4);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &arr[i]);
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        if (a == 1)
            update(1, 1, N, b, c);
        else
            printf("%lld\n", sum(1, 1, N, b, c));
    }
}
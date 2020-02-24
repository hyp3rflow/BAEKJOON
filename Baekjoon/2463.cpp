#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

typedef struct node
{
    int first, second, weight;
    node(int x, int y, int w) : first(x), second(y), weight(w) {}
} Node;

const int MAX = 1e6;
const int mod = 1e9;
int N, M, x, y, w;
int parent[MAX];
ll size[MAX], total = 0, res = 0;
vector<Node> edge;

int find(int n)
{
    if (parent[n] == n)
        return n;
    return parent[n] = find(parent[n]);
}

void merge(int m, int n)
{
    parent[n] = m;
    size[m] += size[n];
    size[n] = 1;
}

bool cmp(const Node &a, const Node &b)
{
    return a.weight > b.weight;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        edge.push_back(node(x, y, w));
        total += w;
    }

    sort(edge.begin(), edge.end(), cmp);

    int edgesize = edge.size();
    for (int i = 0; i < edgesize; i++)
    {
        int x = find(edge[i].first);
        int y = find(edge[i].second);
        int w = edge[i].weight;

        if (x != y)
        {
            res += (((size[x] * size[y]) % mod) * total) % mod;
            res %= mod;
            merge(x, y);
        }

        total -= w;
    }

    printf("%lld", res);

    return 0;
}
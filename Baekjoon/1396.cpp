#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

int N, M, Q;
vector<pair<int, pair<int, int>>> v;
vector<vector<int>> t;

const int MAX = 22;
int parent[200020], size[200020], g[200020], depth[200020], par[200020][22];

int find(int p)
{
    return parent[p] == p ? p : parent[p] = find(parent[p]);
}

void merge(int a, int b)
{
    if (find(a) == find(b))
        return;
    else
    {
        parent[find(b)] = find(a);
    }
}

void dfs(int curr)
{
    for (auto next : t[curr])
    {
        if (depth[next] == 0)
        {
            par[next][0] = curr;
            depth[next] = depth[curr] + 1;
            dfs(next);
        }
    }
}

int LCA(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    int diff = depth[x] - depth[y];

    for (int j = 0; diff; j++)
    {
        if (diff % 2)
            x = par[x][j];
        diff /= 2;
    }

    if (x != y)
    {
        for (int j = MAX - 1; j >= 0; j--)
        {
            if (par[x][j] != -1 && par[x][j] != par[y][j])
            {
                x = par[x][j];
                y = par[y][j];
            }
        }
        x = par[x][0];
    }

    return x;
}

int main()
{
    scanf("%d %d", &N, &M);
    t.resize(N + M + 1);
    for (int i = 1; i <= N + M; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({c, {a, b}});
    }

    memset(par, -1, sizeof(par));

    sort(v.begin(), v.end());

    for (int i = N + 1; i <= N + M; i++)
    {
        int x = v[i - N - 1].second.first;
        int y = v[i - N - 1].second.second;
        int w = v[i - N - 1].first;

        if (find(x) == find(y))
            continue;

        size[i] = size[find(x)] + size[find(y)];
        g[i] = w;

        t[i].push_back(find(x));
        t[i].push_back(find(y));

        merge(i, x);
        merge(i, y);
    }

    for (int i = N + M; i > 0; i--)
    {
        if (!depth[i])
            dfs(i);
    }

    for (int j = 0; j < MAX - 1; j++)
    {
        for (int i = 1; i <= N + M; i++)
        {
            if (par[i][j] != -1)
                par[i][j + 1] = par[par[i][j]][j];
        }
    }

    scanf("%d", &Q);

    for (int i = 0; i < Q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if (find(x) != find(y))
        {
            printf("-1\n");
            continue;
        }

        int tmp = LCA(x, y);
        printf("%d %d\n", g[tmp], size[tmp]);
    }

    return 0;
}
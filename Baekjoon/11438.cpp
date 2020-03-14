#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, d[100010], a, b;
int parent[100010][18];
vector<int> v[100010];

int LCA(int a, int b)
{
    if (d[a] < d[b])
        swap(a, b);
    int diff = d[a] - d[b];

    for (int j = 0; diff; j++)
    {
        if (diff % 2)
            a = parent[a][j];
        diff /= 2;
    }

    if (a != b)
    {
        for (int j = 18 - 1; j >= 0; j--)
        {
            if (parent[a][j] != -1 && parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        a = parent[a][0];
    }

    return a;
}

void init(int curr)
{
    for (int next : v[curr])
    {
        if (d[next] == -1)
        {
            parent[next][0] = curr;
            d[next] = d[curr] + 1;
            init(next);
        }
    }
}

int main()
{
    scanf("%d", &N);

    memset(parent, -1, sizeof(parent));
    fill(d, d + N + 1, -1);
    d[1] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    init(1);
    for (int j = 0; j < 18 - 1; j++)
    {
        for (int i = 2; i <= N; i++)
        {
            if (parent[i][j] != -1)
            {
                parent[i][j + 1] = parent[parent[i][j]][j];
            }
        }
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
}
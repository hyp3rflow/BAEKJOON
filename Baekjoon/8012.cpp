#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 16;
int N, M, a, b, depth[30010], parent[30010][MAX];
vector<int> v[30010];

void init(int curr)
{
    for (int next : v[curr])
    {
        if (depth[next] == -1)
        {
            depth[next] = depth[curr] + 1;
            parent[next][0] = curr;
            init(next);
        }
    }
}

int dist(int a, int b)
{
    int fst = a;
    int snd = b;

    if (depth[a] < depth[b])
        swap(a, b);
    int diff = depth[a] - depth[b];

    for (int j = 0; diff; j++)
    {
        if (diff % 2)
        {
            a = parent[a][j];
        }
        diff /= 2;
    }

    if (a != b)
    {
        for (int j = MAX - 1; j >= 0; j--)
        {
            if (parent[a][j] != -1 && parent[a][j] != parent[b][j])
            {
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        a = parent[a][0];
    }

    return depth[fst] - depth[a] + depth[snd] - depth[a];
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    init(1);

    for (int j = 0; j < MAX - 1; j++)
    {
        for (int i = 2; i <= N; i++)
        {
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];
        }
    }

    scanf("%d", &M);
    int curr, next, result = 0;
    scanf("%d", &curr);
    for (int i = 1; i < M; i++)
    {
        scanf("%d", &next);
        result += dist(curr, next);
        curr = next;
    }

    printf("%d", result);

    return 0;
}
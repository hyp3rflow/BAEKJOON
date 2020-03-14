#include <cstdio>
#include <vector>

using namespace std;

int N, tmp, degree[1010], visited[1010];
vector<int> adj[1010];

int compSize(int curr)
{
    int size = 1;
    visited[curr] = 1;
    for (int i = 0; i < N; i++)
    {
        if (adj[curr][i] && !visited[i])
        {
            size += compSize(i);
        }
    }

    return size;
}

void func(int curr)
{
    for (int i = 0; i < N; i++)
    {
        if (adj[curr][i])
        {
            adj[curr][i]--;
            adj[i][curr]--;

            func(i);
        }
    }
    
    printf("%d ", curr + 1);
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        adj[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &tmp);
            if (j > i && tmp)
            {
                adj[i][j] = tmp;
                adj[j][i] = tmp;
                degree[i] += tmp;
                degree[j] += tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (degree[i] % 2)
        {
            puts("-1");
            return 0;
        }
    }

    bool flag = false;
    int start = -1;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            int size = compSize(i);
            if (size > 1)
            {
                if (flag)
                {
                    puts("-1");
                    return 0;
                }
                else
                {
                    start = i;
                    flag = true;
                }
            }
        }
    }
    if (start == -1)
        start = 0;

    func(start);

    return 0;
}
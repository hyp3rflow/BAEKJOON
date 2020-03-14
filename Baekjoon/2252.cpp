#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, indegree[32010], result[32010];
queue<int> q;
vector<int> v[32010];

int main()
{
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        indegree[b]++;
        v[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        int curr = q.front();
        q.pop();

        result[i] = curr;
        for (int next : v[curr])
        {
            if (!--indegree[next])
            {
                q.push(next);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}
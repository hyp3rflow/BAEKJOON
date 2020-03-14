#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, indegree[1010];
vector<int> v[1010];

int main()
{
    scanf("%d %d", &N, &M);

    for (int j = 0; j < M; j++)
    {
        int num, tmp, prev;
        scanf("%d", &num);
        if (!num)
            continue;

        scanf("%d", &prev);
        for (int i = 1; i < num; i++)
        {
            scanf("%d", &tmp);
            indegree[tmp]++;
            v[prev].push_back(tmp);
            prev = tmp;
        }
    }

    int result[1010];
    queue<int> Q;

    for (int i = 1; i <= N; i++)
    {
        if (!indegree[i])
            Q.push(i);
    }

    for (int i = 1; i <= N; i++)
    {
        if (Q.empty())
        {
            puts("0");
            return 0;
        }

        int curr = Q.front();
        Q.pop();

        result[i] = curr;
        for (int next : v[curr])
            if (!--indegree[next])
                Q.push(next);
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", result[i]);
    }
}
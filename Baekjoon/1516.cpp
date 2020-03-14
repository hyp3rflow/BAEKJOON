#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int tim[550], indegree[550], res[550];
vector<int> v[550];
queue<int> Q;

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        int tmp;
        scanf("%d", &tmp);

        tim[i] = tmp;

        scanf("%d", &tmp);
        while (tmp != -1)
        {
            v[tmp].push_back(i);
            indegree[i]++;
            scanf("%d", &tmp);
        }

        if (!indegree[i])
        {
            res[i] = tim[i];
            Q.push(i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        int curr = Q.front();
        Q.pop();
        for (int next : v[curr])
        {
            res[next] = max(res[next], res[curr] + tim[next]);
            if (--indegree[next] == 0)
                Q.push(next);
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", res[i + 1]);
    }

    return 0;
}
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, N, M, a, b;
int arr[510][510], v[510], indegree[510];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(arr, 0, sizeof(arr));
        memset(indegree, 0, sizeof(indegree));

        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &v[i]);

        for (int i = 1; i <= N; ++i)
        {
            for (int j = i + 1; j <= N; ++j)
            {
                arr[v[i]][v[j]] = 1;
                indegree[v[j]]++;
            }
        }

        scanf("%d", &M);
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d", &a, &b);
            if (arr[a][b])
            {
                arr[a][b] = 0;
                arr[b][a] = 1;
                indegree[b]--, indegree[a]++;
            }
            else
            {
                arr[b][a] = 0;
                arr[a][b] = 1;
                indegree[a]--, indegree[b]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= N; ++i)
            if (!indegree[i])
                q.push(i);

        bool chk = true;

        vector<int> ans;
        while (!q.empty())
        {
            if (q.size() > 1)
            {
                chk = false;
                break;
            }

            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (int next = 1; next <= N; next++)
            {
                if (arr[curr][next])
                {
                    indegree[next]--;
                    if (!indegree[next])
                        q.push(next);
                }
            }
        }

        if (!chk)
            puts("?");
        else if (ans.size() == N)
        {
            for (int i = 0; i < N; ++i)
                printf("%d ", ans[i]);
            puts("");
        }
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}

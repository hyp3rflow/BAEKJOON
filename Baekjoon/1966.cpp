#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pp;

queue<pp> q;
priority_queue<int> pq;

int T, N, M;

int main()
{
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);

        while(!q.empty())
            q.pop();
        while(!pq.empty())
            pq.pop();

        for (int j = 0; j < N; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (j == M)
                q.push(make_pair(tmp, 1));
            else
                q.push(make_pair(tmp, 0));
            pq.push(tmp);
        }

        int flg = 0;
        int cnt = 1;
        while (!q.empty())
        {
            if (pq.top() == q.front().first)
            {
                if (q.front().second)
                {
                    flg = 1;
                    break;
                }
                q.pop();
                pq.pop();
                cnt++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }

        if (flg)
            printf("%d\n", cnt);
    }
}
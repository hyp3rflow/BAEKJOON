#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int N, tmp;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &tmp);
        if (tmp == 0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
            pq.push(tmp);
    }
}
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;

int N;
char str[20];

int main()
{
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        scanf("%[^\n]s", str);
        getchar();

        if (str[0] == 'p')
        {
            if (str[1] == 'u') // push 4
            {
                q.push(atoi(str + 5));
            }
            else
            {
                printf("%d\n", !q.empty() ? q.front() : -1);
                if(!q.empty())
                    q.pop();
            }
        }
        else if (str[0] == 's')
        {
            printf("%lu\n", q.size());
        }
        else if (str[0] == 'e')
        {
            printf("%d\n", q.empty() ? 1 : 0);
        }

        else if (str[0] == 'f')
        {
            printf("%d\n", !q.empty() ? q.front() : -1);
        }
        else if (str[0] == 'b')
        {
            printf("%d\n", !q.empty() ? q.back() : -1);
        }
    }
}
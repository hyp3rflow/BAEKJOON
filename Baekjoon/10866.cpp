#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> dq;
int N;
char arr[20];

int main()
{
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++)
    {
        scanf("%[^\n]s", arr);
        getchar();

        if (arr[0] == 'p')
        {
            // push_
            if (arr[4] == '_')
            {
                if (arr[5] == 'b')
                {
                    dq.push_back(atoi(arr + 10));
                }
                else
                {
                    dq.push_front(atoi(arr + 11));
                }
            }
            // pop_
            else
            {
                if (arr[4] == 'f')
                {
                    printf("%d\n", !dq.empty() ? dq.front() : -1);
                    if(!dq.empty()) dq.pop_front();
                }
                else
                {
                    printf("%d\n", !dq.empty() ? dq.back() : -1);
                    if(!dq.empty()) dq.pop_back();
                }
            }
        }
        else if (arr[0] == 'f')
        {
            printf("%d\n", !dq.empty() ? dq.front() : -1);
        }
        else if (arr[0] == 'e')
        {
            printf("%d\n", dq.empty() ? 1 : 0);
        }
        else if (arr[0] == 's')
        {
            printf("%lu\n", dq.size());
        }
        else if (arr[0] == 'b')
        {
            printf("%d\n", !dq.empty() ? dq.back() : -1);
        }
    }
}
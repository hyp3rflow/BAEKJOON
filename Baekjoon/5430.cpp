#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

int T, n;
char func[100010];
char str[20000000];
deque<int> dq;

int main()
{
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++)
    {
        scanf("%[^\n]s", func);
        getchar();

        scanf("%d", &n);
        getchar();

        scanf("%[^\n]s", str);
        getchar();

        int step = 0;
        for (int j = 0; j < n; j++)
        {
            while (!(str[step] == '[' || str[step] == ','))
            {
                step++;
            }
            dq.push_back(atoi(str + step + 1));
            step++;
        }

        int flag = 0, cnt = 0;

        // 여기서 condition문에 j < strlen(func) -> condition문 check할때마다 strlen 계산하므로 시간초과남.
        for (int j = 0; func[j]; j++)
        {
            if (func[j] == 'R')
            {
                cnt++;
            }
            else
            {
                if (!dq.empty())
                {
                    cnt % 2 ? dq.pop_back() : dq.pop_front();
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag)
        {
            printf("error\n");
            while (!dq.empty())
            {
                dq.pop_back();
            }
        }
        else
        {
            printf("[");
            if (cnt % 2)
            {
                while (!dq.empty())
                {
                    printf("%d", dq.back());
                    dq.pop_back();
                    if (!dq.empty())
                        printf(",");
                }
            }
            else
            {
                while (!dq.empty())
                {
                    printf("%d", dq.front());
                    dq.pop_front();
                    if (!dq.empty())
                        printf(",");
                }
            }
            printf("]\n");
        }
    }
}
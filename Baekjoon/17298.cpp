#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

typedef pair<int, int> pp;

int N, NGE[1000010], tmp, cnt, number[1000010];
stack<pp> st;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < 1000010; i++)
    {
        NGE[i] = -1;
    }

    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &tmp);

        if (st.empty())
            st.push(make_pair(tmp, i));
        else
        {
            cnt = 1;
            while (!st.empty() && st.top().first < tmp)
            {
                NGE[st.top().second] = tmp;
                st.pop();
                cnt++;
            }
            st.push(make_pair(tmp, i));
        }
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d ", NGE[i]);
    }
}
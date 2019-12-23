#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int K, tmp, res;
stack<int> st;

int main()
{
    scanf(" %d", &K);

    for (int i = 0; i < K; i++)
    {
        scanf(" %d", &tmp);

        if (tmp)
            st.push(tmp);
        else
            st.pop();
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    printf("%d", res);

    return 0;
}

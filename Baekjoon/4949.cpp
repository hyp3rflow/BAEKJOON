#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

char arr[110];
stack<char> st;

int flag;

int main()
{
    while (true)
    {
        while (!st.empty())
            st.pop();
        flag = 1;

        scanf("%[^\n]s", arr);
        getchar();

        if (arr[0] == '.' && !arr[1])
        {
            break;
        }
        else
        {
            for (int i = 0; arr[i]; i++)
            {
                if (arr[i] == '(' || arr[i] == '[')
                    st.push(arr[i]);
                else if (arr[i] == ')' || arr[i] == ']')
                {
                    if (st.empty())
                    {
                        flag = 0;
                        break;
                    }
                    else
                    {
                        if (arr[i] == ')' && st.top() == '(')
                            st.pop();
                        else if (arr[i] == ']' && st.top() == '[')
                            st.pop();
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        
        if(!st.empty())
            flag = 0;

        printf("%s\n", flag ? "yes" : "no");
    }

    return 0;
}
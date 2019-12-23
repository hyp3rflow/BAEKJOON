#include <cstdio>
#include <algorithm>

using namespace std;

char arr[51];
int result, tmp, flag;

int main()
{
    scanf("%s", arr);

    for (int i = 0; arr[i]; i++)
    {
        if (arr[i] == '+' || arr[i] == '-')
        {
            if (flag == 1)
            {
                result -= tmp;
            }
            else
            {
                result += tmp;
            }
            if (arr[i] == '-')
            {
                flag = 1;
            }
            tmp = 0;
        }
        else
        {
            tmp *= 10;
            tmp += arr[i] - '0';
        }
    }

    if(tmp){
        if(flag){
            result -= tmp;
        }
        else result += tmp;
    }

    printf("%d", result);
}
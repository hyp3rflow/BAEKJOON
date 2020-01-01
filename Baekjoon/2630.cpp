#include <cstdio>
#include <algorithm>

using namespace std;

int N, tmp;
int white, blue;
int arr[129][129];

void func(int x, int y, int a, int b)
{
    int crit = arr[x][y];
    bool state = true;
    for (int i = x; i <= a; i++)
    {
        if (!state)
            break;

        for (int j = y; j <= b; j++) 
        {
            if (crit != arr[i][j])
            {
                state = false;
                break;
            }
        }
    }

    if (state)
    {
        if (crit)
        {
            blue++;
        }
        else
            white++;
    }
    else
    {
        // center -> (x+a)/2, (y+b)/2
        func(x, y, (x + a) / 2, (y + b) / 2);
        func((x + a) / 2 + 1, y, a, (y + b) / 2);
        func(x, (y + b) / 2 + 1, (a + x) / 2, b);
        func((x + a) / 2 + 1, (y + b) / 2 + 1, a, b);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf(" %d", &arr[i][j]);
        }
    }

    func(1, 1, N, N);
    printf("%d\n%d", white, blue);
}
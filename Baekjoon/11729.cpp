#include <cstdio>

using namespace std;

int cnt = 1, K;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
        printf("%d %d\n", from, to);
    else
    {
        hanoi(n - 1, from, to, by);
        hanoi(1, from, by, to);
        hanoi(n - 1, by, from, to);
    }
}

int main()
{
    scanf("%d", &K);
    for (int i = 1; i <= K; i++)
        cnt *= 2;
    printf("%d\n", cnt - 1);
    hanoi(K, 1, 2, 3);
}
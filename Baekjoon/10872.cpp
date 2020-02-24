#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    scanf("%d", &n);
    printf("%d", factorial(n));
}
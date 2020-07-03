#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

long long N, k, dp[1 << 15][101];
vector<string> arr(15);
int num[15], pow[52];

ll gcd(ll m, ll n)
{
    if (!n)
        return m;
    return gcd(n, m % n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> k;

    for (int i = 0; i < N; i++)
    {
        int length = arr[i].length();
        for (int j = 0; j < length; j++)
        {
            num[i] *= 10;
            num[i] += arr[i][j] - '0';
            num[i] %= k;
        }
    }

    pow[0] = 1;
    for (int p = 1; p < 52; p++)
    {
        pow[p] = (pow[p - 1] * 10);
        pow[p] %= k;
    }

    dp[0][0] = 1;
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < N; l++)
            {
                if (!(i & (1 << l)))
                {
                    int next = j * pow[arr[l].length()];
                    next %= k;
                    next += num[l];
                    next %= k;
                    dp[i | (1 << l)][next] += dp[i][j];
                }
            }
        }
    }

    ll p = dp[(1 << N) - 1][0];
    ll q = 1;
    for (int i = 2; i <= N; i++)
        q *= i;
    ll g = gcd(p, q);

    cout << p / g << '/' << q / g;

    return 0;
}
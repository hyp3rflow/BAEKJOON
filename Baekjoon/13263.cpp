#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, a[100010], b[100010];

struct Line
{
    ll a, b;
    double s;

    Line() : Line(1, 0) {}
    Line(ll a1, ll b1) : a(a1), b(b1), s(0) {}
};

inline double cross(Line &f, Line &g)
{
    return (g.b - f.b) / (f.a - g.a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll dp[100010] = {0};
    Line f[100010];
    int top = 0;

    for (int i = 1; i < n; i++)
    {
        Line g(b[i - 1], dp[i - 1]);
        while (top)
        {
            g.s = cross(f[top - 1], g);
            if (f[top - 1].s < g.s)
                break;
            top--;
        }
        f[top++] = g;

        ll x = a[i];
        int pos = top - 1;
        if (x < f[top - 1].s)
        {
            int start = 0, end = top - 1;
            while (start + 1 < end)
            {
                int mid = (start + end) / 2;
                if (x < f[mid].s)
                {
                    end = mid;
                }
                else
                    start = mid;
            }
            pos = start;
        }
        dp[i] = f[pos].a * x + f[pos].b;
    }

    cout << dp[n - 1];

    return 0;
}
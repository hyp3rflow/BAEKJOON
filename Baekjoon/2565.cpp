#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pp;

int N, a, b, dp[1000];
vector<pp> v;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf(" %d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    int maxx = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
            {
                m = max(m, dp[j]);
            }
        }
        dp[i] = m + 1;
        maxx = max(maxx, dp[i]);
    }

    printf("%d", v.size() - maxx);

    return 0;
}
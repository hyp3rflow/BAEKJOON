#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, k, arr[1010][2];

int distance(int a, int b, int c, int d)
{
    return (a - c) * (a - c) + (b - d) * (b - d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    arr[n][0] = 10000;
    arr[n][1] = 10000;

    int start = 1,
        end = distance(0, 0, 10000, 10000);

    while (start <= end)
    {
        // cout << start << "->" << end << endl;
        int mid = (start + end) / 2;

        bool flag = false;
        int visit[1010] = {0};
        queue<pair<pair<int, int>, int>> q;

        q.push({{0, 0}, 0});
        while (!q.empty())
        {
            pair<int, int> p = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if (p.first == 10000 && p.second == 10000)
            {
                flag = true;
                break;
            }

            if (cnt == k + 1)
            {
                continue;
            }

            for (int i = 0; i <= n; i++)
            {
                if (!visit[i] && distance(p.first, p.second, arr[i][0], arr[i][1]) <= mid)
                {
                    // cout << p.first << "," << p.second << " -> " << arr[i][0] << "," << arr[i][1] << " ? " << mid << " : " << visit[i] << endl;
                    visit[i] = 1;
                    q.push({{arr[i][0], arr[i][1]}, cnt + 1});
                }
            }
        }

        if (flag)
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << (int)ceil(sqrt(start) / 10);

    return 0;
}
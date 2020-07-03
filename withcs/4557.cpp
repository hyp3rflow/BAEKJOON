// 컴퓨터프로그래밍I 2020 WithCS Term Project3 (Hard Sudoku)

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int a, n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<pair<int, int>, int>> q;

int main()
{
    cin >> a >> n >> m;
    int t[10][10], arr[10][10] = {0};

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> t[i][j];

    arr[0][0] = 1;
    q.push(make_pair(make_pair(0, 0), 1));
    while (!q.empty())
    {
        pair<int, int> p = q.front().first;
        int x = p.first, y = p.second;
        int height = t[x][y];
        int level = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i], next_y = y + dy[i];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
            {
                if (t[next_x][next_y] - level >= 0 && abs(t[next_x][next_y] - height) <= a)
                {
                    if (arr[next_x][next_y] == 0)
                    {
                        arr[next_x][next_y] = level;
                        q.push(make_pair(make_pair(next_x, next_y), level + 1));
                    }
                }
            }
        }
    }

    if (arr[m - 1][n - 1])
        cout << arr[m - 1][n - 1];
    else
        cout << "IMPOSSIBLE";
}
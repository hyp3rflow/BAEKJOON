#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int N, M, tmp, cnt = 0;
map<vector<int>, int> v;
map<int, vector<int>> v2;
vector<int> adj[1010], ans;
pair<int, int> chk[1010];

int vertice(vector<int> node)
{
    if (v.find(node) != v.end())
    {
        return v[node];
    }
    else
    {
        v[node] = cnt;
        v2[cnt] = node;
        return cnt++;
    }
}

void DFS(int curr)
{
    while (!adj[curr].empty())
    {
        int next = adj[curr].back();
        adj[curr].pop_back();
        DFS(next);
    }
    ans.push_back(curr);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N - M + 1; i++)
    {
        vector<int> fst, snd;
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &tmp);
            if (j == 0)
                fst.push_back(tmp);
            else if (j == M - 1)
                snd.push_back(tmp);
            else
            {
                fst.push_back(tmp);
                snd.push_back(tmp);
            }
        }
        int f = vertice(fst);
        int s = vertice(snd);

        chk[f].second++;
        chk[s].first++;
        adj[f].push_back(s);
    }

    int start;

    for (int i = 0; i < cnt; i++)
    {
        if (chk[i].second > chk[i].first)
        {
            start = i;
            break;
        }
        else
        {
            if (chk[i].second)
                start = i;
        }
    }

    DFS(start);

    vector<int> st = v2[start];
    for (int i = 0; i < M - 1; i++)
    {
        int res = st[i];
        cout << res << ' ';
    }

    int size = ans.size();

    reverse(ans.begin(), ans.end());
    for (int i = 1; i < size; i++)
    {
        int res = v2[ans[i]].back();
        cout << res << ' ';
    }
}
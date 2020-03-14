#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int K, M, C;
vector<int> adj[10000010];
vector<int> ans;

void DFS(int curr)
{
    while (!adj[curr].empty())
    {
        int next = adj[curr].back();
        adj[curr].pop_back();
        DFS(next);
    }
    ans.push_back(curr % K);
}

int main()
{
    scanf("%d %d", &K, &M);

    if (M == 1)
    {
        for (int i = 0; i < K; i++)
        {
            cout << i << ' ';
        }
        return 0;
    }

    int MAX = pow(K, M - 1);
    int modMAX = pow(K, M - 2);
    for (int i = 0; i < MAX; i++)
    {
        int curr = i;
        curr %= modMAX;
        curr *= K;
        for (int j = 0; j < K; j++)
            adj[i].push_back(curr + j);
    }

    stack<int> s;
    s.push(0);
    while (!s.empty())
    {
        int curr = s.top();
        if (adj[curr].empty())
        {
            ans.push_back(curr % K);
            s.pop();
        }
        else
        {
            int next = adj[curr].back();
            adj[curr].pop_back();
            s.push(next);
        }
    }

    if (ans.size() < pow(K, M))
    {
        puts("-1");
    }
    else
    {
        reverse(ans.begin(), ans.end());
        int size = ans.size();
        for (int i = 0; i < size; i++)
        {
            printf("%d ", ans[i]);
        }
    }

    return 0;
}
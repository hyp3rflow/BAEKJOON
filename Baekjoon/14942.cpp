#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, a, b, c;
const int MAX = 1e5 + 10;
const int MAX_D = 17;

int visit[MAX];
int ant[MAX][MAX_D];
int dist[MAX][MAX_D];
int energy[MAX];
vector<pair<int, int>> adj[MAX];
queue<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> energy[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    s.push(1);
    visit[1] = 1;
    while (!s.empty()) {
        int front = s.front();
        s.pop();

        for (auto &p : adj[front]) {
            int next = p.first;
            int d = p.second;

            if (visit[next])
                continue;

            visit[next] = 1;
            ant[next][0] = front;
            dist[next][0] = d;

            s.push(next);
        }
    }

    for (int j = 1; j < MAX_D; j++) {
        for (int i = 1; i <= n; i++) {
            ant[i][j] = ant[ant[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[ant[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        int tmp = energy[i];
        int curr = i;
        for (int j = MAX_D - 1; j >= 0; j--) {
            if (tmp <= 0)
                break;
            if (tmp >= dist[curr][j] && ant[curr][j] != 0) {
                tmp -= dist[curr][j];
                curr = ant[curr][j];
            }
        }

        cout << curr << "\n";
    }
}
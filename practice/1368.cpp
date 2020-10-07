#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int uf[1010], N;

int find(int a) {
    if (uf[a] < 0)
        return a;
    return uf[a] = find(uf[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
        return false;
    }
    uf[b] = a;
    return true;
}

struct Edge {
    int u, v, w;
    Edge() : Edge(-1, -1, 0) {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &O) const { return w < O.w; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[1010], tmp;
    Edge e[100010];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;

        arr[i] = tmp;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp == 0)
                continue;
        
        }
    }
}
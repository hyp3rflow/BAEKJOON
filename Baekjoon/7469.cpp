#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int i, j, k, p;
const int stMAX = 1 << 18;
vector<int> tree[stMAX];

struct SegTree {
    int start = stMAX / 2;

    void update(int l, int r, int value) {
        update(l, r, 1, 0, start - 1, value);
    }
    void update(int l, int r, int node, int ns, int ne, int value) {
        if (r < ns || ne < l) {
            return;
        }
        tree[node].push_back(value);
        if (node < start) {
            int mid = ns + ne >> 1;
            update(l, r, node * 2, ns, mid, value);
            update(l, r, node * 2 + 1, mid + 1, ne, value);
        }
    }

    int find(int s, int e, int value) {
        return find(s, e, 1, 0, start - 1, value);
    }
    int find(int s, int e, int node, int ns, int ne, int value) {
        if (e < ns || ne < s) {
            return 0;
        }
        if (s <= ns && ne <= e) {
            return upper_bound(tree[node].begin(), tree[node].end(), value) - tree[node].begin();
        }
        int mid = ns + ne >> 1;
        return find(s, e, node * 2, ns, mid, value) + find(s, e, node * 2 + 1, mid + 1, ne, value);
    }
} st;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> p;
        st.update(i, i, p);
    }

    for (int i = 0; i < stMAX; i++) {
        sort(tree[i].begin(), tree[i].end());
    }

    for (int a = 0; a < M; a++) {
        cin >> i >> j >> k;

        int r = 1e9;
        int l = -r;
        int mid = l + r >> 1;

        while (l <= r) {
            mid = l + r >> 1;
            if (st.find(i - 1, j- 1, mid) < k)
                l = mid + 1;
            else
                r = mid - 1;
        }

        cout << l << "\n";
    }
}
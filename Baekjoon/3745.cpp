#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX = 1 << 21;

int n, p;
ll arr[MAX];

struct SegTree {
    int start;

    SegTree() {
        start = MAX / 2;
        fill(arr, arr + MAX, 0);
    }

    void init() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    }

    int sum(int s, int e) { return sum(s, e, 1, 0, start - 1); }
    int sum(int s, int e, int node, int ns, int ne) {
        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e) {
            return arr[node];
        }

        int mid = (ns + ne) / 2;
        return max(sum(s, e, node * 2, ns, mid), sum(s, e, node * 2 + 1, mid + 1, ne));
    }

    void update(int idx, int value) {
        arr[start + idx] = value;
        for (int i = (start + idx) / 2; i > 0; i /= 2) {
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n) {
        SegTree st;

        pair<int, int> p[n];
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            p[i] = make_pair(tmp, i);
        }

        sort(p, p + n, [](pair<int, int> &p1, pair<int, int> &p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            return p1.first < p2.first;
        });

        for (pair<int, int> v : p) {
            int result = st.sum(0, v.second);
            st.update(v.second, result + 1);
        }

        cout << st.sum(0, st.start - 1) << "\n";
    }
}
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1 << 21;
ll arr[MAX];

int N, M, x, i, j, k;

struct SegTree {
    int start;

    SegTree() {
        start = MAX / 2;
        fill(arr, arr + MAX, 0);
    }

    void init() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    ll sum(int s, int e) {
        return sum(s, e, 1, 0, start - 1);
    }

    ll sum(int s, int e, int node, int ns, int ne) {
        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e) {
            return arr[node];
        }

        int mid = (ns + ne) / 2;
        return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid + 1, ne);
    }

    void update(int idx, int value) {
        arr[start + idx] = value;
        for (int i = (start + idx) / 2; i > 0; i /= 2) {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    SegTree st;

    for (int p = 0; p < M; p++) {
        cin >> x;
        if (x == 0) {
            // sum function
            cin >> i >> j;
            ll result;
            if (i > j)
                swap(i, j);
            cout << st.sum(i - 1, j - 1) << "\n";
        } else {
            // modify function
            cin >> i >> k;
            st.update(i - 1, k);
        }
    }

    return 0;
}
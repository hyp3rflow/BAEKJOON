// lazy propagation implemented by kks227
// http://blog.naver.com/kks227

#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 1 << 21;
ll arr[MAX], lazy[MAX];

struct SegTree {
    int start;

    SegTree() {
        start = MAX / 2;
        fill(arr, arr + MAX, 0);
        fill(lazy, lazy + MAX, 0);
    }

    void construct() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    // 구간 [nodeStart, nodeEnd)
    // lazy node를 자식 노드로 미는 것이다.
    void propagate(int node, int nodeStart, int nodeEnd) {
        if (lazy[node]) {
            if (node < start) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }

            arr[node] += lazy[node] * (nodeEnd - nodeStart);
            lazy[node] = 0;
        }
    }

    // [s, e)에 k를 더하기
    void add(int s, int e, int k) { add(s, e, k, 1, 0, start); }

    void add(int s, int e, int k, int node, int nodeStart, int nodeEnd) {
        propagate(node, nodeStart, nodeEnd);

        if (e <= nodeStart || nodeEnd <= s)
            return;
        if (s <= nodeStart && nodeEnd <= e) {
            lazy[node] += k;
            propagate(node, nodeStart, nodeEnd);
            return;
        }

        int mid = (nodeStart + nodeEnd) / 2;
        add(s, e, k, node * 2, nodeStart, mid);
        add(s, e, k, node * 2 + 1, mid, nodeEnd);

        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    ll sum(int s, int e) { return sum(s, e, 1, 0, start); }
    ll sum(int s, int e, int node, int nodeStart, int nodeEnd) {
        propagate(node, nodeStart, nodeEnd);

        if (e <= nodeStart || nodeEnd <= s) {
            return 0;
        }

        if (s <= nodeStart && nodeEnd <= e) {
            return arr[node];
        }

        int mid = (nodeStart + nodeEnd) / 2;

        return sum(s, e, node * 2, nodeStart, mid) +
               sum(s, e, node * 2 + 1, mid, nodeEnd);
    }
};

int N, M, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    SegTree st;

    for (int i = 0; i < N; i++) {
        cin >> arr[st.start + i];
    }

    st.construct();

    int a, b, c, d;
    for (int i = 0; i < M + K; i++) {
        cin >> a;

        if (a == 1) {
            cin >> b >> c >> d;
            st.add(b - 1, c, d);
        } else {
            cin >> b >> c;
            cout << st.sum(b - 1, c) << endl;
        }
    }
}
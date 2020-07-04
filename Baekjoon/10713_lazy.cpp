#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1 << 18;
int arr[MAX], lazy[MAX];
int N, M, p[(int)1e5 + 10];

int A[(int)1e5 + 10], B[(int)1e5 + 10], C[(int)1e5 + 10];

struct SegTree {
    int start = MAX / 2;

    SegTree() {
        fill(arr, arr + MAX, 0);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l)
            return 0;
        if (l <= s && e <= r)
            return arr[node];
        int m = s + e >> 1;
        return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
    }

    void propagate(int node, int ns, int ne) {
        if (lazy[node]) {
            if (node < start) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }

            arr[node] += lazy[node] * (ne - ns + 1);
            lazy[node] = 0;
        }
    }

    void add(int s, int e, int k) { add(s, e, k, 1, 0, start - 1); }
    void add(int s, int e, int k, int node, int ns, int ne) {
        propagate(node, ns, ne);

        if (e < ns || ne < s)
            return;
        if (s <= ns && ne <= e) {
            lazy[node] += k;
            propagate(node, ns, ne);
            return;
        }

        int mid = (ns + ne) / 2;
        add(s, e, k, node * 2, ns, mid);
        add(s, e, k, node * 2 + 1, mid + 1, ne);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }
};

int main() {
    cin >> N >> M;

    SegTree st;

    for (int i = 1; i <= M; i++) {
        cin >> p[i];
    }

    for (int i = 2; i <= M; i++) {
        int prev = p[i - 1];
        int next = p[i];

        if (prev > next)
            swap(prev, next);

        st.add(prev - 1, next - 2, 1);
    }

    for (int i = 1; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    ll r = 0;

    for (int i = 1; i < N; i++) {
        ll result = st.query(1, 0, st.start - 1, i - 1, i - 1);
        r += min(result * A[i], result * B[i] + C[i]);
    }

    cout << r;
}
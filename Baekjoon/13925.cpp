#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_st = 1 << 18;
const int MOD = 1e9 + 7;
ll tree[MAX_st], lazyAdd[MAX_st], lazyMul[MAX_st];

struct SegTree {
    int start = MAX_st >> 1;

    SegTree() {
        fill(tree, tree + MAX_st, 0);
        fill(lazyAdd, lazyAdd + MAX_st, 0);
        fill(lazyMul, lazyMul + MAX_st, 1);
    }

    void construct() {
        for (int i = start - 1; i > 0; i--) {
            tree[i] = ((tree[i * 2] % MOD) + (tree[i * 2 + 1] % MOD)) % MOD;
        }
    }

    void propagate(int node, int ns, int ne) {
        if (lazyAdd[node] || lazyMul[node] != 1) {
            if (node < start) {
                lazyMul[node * 2] *= lazyMul[node];
                lazyMul[node * 2 + 1] *= lazyMul[node];

                lazyMul[node * 2] %= MOD;
                lazyMul[node * 2 + 1] %= MOD;

                lazyAdd[node * 2] *= lazyMul[node];
                lazyAdd[node * 2] += lazyAdd[node];
                lazyAdd[node * 2] %= MOD;

                lazyAdd[node * 2 + 1] *= lazyMul[node];
                lazyAdd[node * 2 + 1] += lazyAdd[node];
                lazyAdd[node * 2 + 1] %= MOD;
            }

            tree[node] = ((tree[node] * lazyMul[node]) % MOD + ((ne - ns + 1) * lazyAdd[node]) % MOD) % MOD;

            lazyMul[node] = 1;
            lazyAdd[node] = 0;
        }
    }

    void add(int s, int e, int a, int m) {
        return add(s, e, a, m, 1, 0, start - 1);
    }

    void add(int s, int e, int a, int m, int node, int ns, int ne) {
        propagate(node, ns, ne);
        if (e < ns || ne < s) {
            return;
        }
        if (s <= ns && ne <= e) {
            lazyMul[node] *= m;

            lazyAdd[node] *= m;
            lazyAdd[node] += a;

            lazyMul[node] %= MOD;
            lazyAdd[node] %= MOD;
            propagate(node, ns, ne);
            return;
        }
        int mid = ns + ne >> 1;
        add(s, e, a, m, node * 2, ns, mid);
        add(s, e, a, m, node * 2 + 1, mid + 1, ne);
        tree[node] = (tree[node * 2] % MOD + tree[node * 2 + 1] % MOD) % MOD;
    }

    ll sum(int s, int e) {
        return sum(s, e, 1, 0, start - 1);
    }

    ll sum(int s, int e, int node, int ns, int ne) {
        propagate(node, ns, ne);
        if (e < ns || ne < s) {
            return 0;
        }
        if (s <= ns && ne <= e) {
            return tree[node] % MOD;
        }

        int mid = ns + ne >> 1;
        return (sum(s, e, node * 2, ns, mid) % MOD + sum(s, e, node * 2 + 1, mid + 1, ne) % MOD) % MOD;
    }
} st;

int N, M, p, x, y, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tree[st.start + i];
    }

    st.construct();

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> p >> x >> y;
        x -= 1;
        y -= 1;
        if (p == 1) {
            cin >> v;
            st.add(x, y, v, 1);
        } else if (p == 2) {
            cin >> v;
            st.add(x, y, 0, v);
        } else if (p == 3) {
            cin >> v;
            st.add(x, y, v, 0);
        } else if (p == 4) {
            cout << st.sum(x, y) % MOD << "\n";
        }
    }
}
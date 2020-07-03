#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int N, M, O, S, T;
const int MAX = 1 << 21;

int arr[MAX];
int lazy[MAX];

struct SegTree {
    int start = MAX / 2;

    SegTree() {
        fill(arr, arr + MAX, 0);
    }

    void propagate(int node, int ns, int ne) {
        if (lazy[node]) {
            if (node < start) {
                lazy[node * 2] ^= 1;
                lazy[node * 2 + 1] ^= 1;

                int value = 0;
                if (lazy[node * 2]) {
                    value += (ne - ns + 1) / 2 - arr[node * 2];
                } else {
                    value += arr[node * 2];
                }

                if (lazy[node * 2 + 1]) {
                    value += (ne - ns + 1) / 2 - arr[node * 2 + 1];
                } else {
                    value += arr[node * 2 + 1];
                }

                arr[node] = value;

            } else {
                arr[node] ^= 1;
            }

            lazy[node] = 0;
        }
    }

    void reverse(int s, int e, int node, int ns, int ne) {
        propagate(node, ns, ne);
        if (e < ns || ne < s)
            return;
        if (s <= ns && ne <= e) {
            lazy[node] ^= 1;
            propagate(node, ns, ne);
            return;
        }

        int mid = (ns + ne) / 2;
        reverse(s, e, node * 2, ns, mid);
        reverse(s, e, node * 2 + 1, mid + 1, ne);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    ll sum(int s, int e) { return sum(s, e, 1, 0, start - 1); }
    ll sum(int s, int e, int node, int ns, int ne) {
        propagate(node, ns, ne);

        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e)
            return arr[node];

        int mid = (ns + ne) / 2;
        return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid + 1, ne);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    SegTree st;

    for (int i = 0; i < M; i++) {
        cin >> O >> S >> T;

        if (O) {
            // query
            cout << st.sum(S - 1, T - 1) << "\n";
        } else {
            // reverse
            st.reverse(S - 1, T - 1, 1, 0, st.start - 1);
        }
    }
}
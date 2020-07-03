#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

int N, p;
const int MAX = 1 << 21;
int arr[MAX];

struct SegTree {
    int start = MAX / 2;

    SegTree() {
        fill(arr, arr + MAX, 0);
    }

    void update(int idx, int value) {
        arr[start + idx] = value;
        for (int i = (start + idx) / 2; i > 0; i /= 2) {
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    }

    int sum(int s, int e) {
        return sum(s, e, 1, 0, start - 1);
    }

    int sum(int s, int e, int node, int ns, int ne) {
        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e) {
            return arr[node];
        }

        int mid = (ns + ne) / 2;
        return max(sum(s, e, node * 2, ns, mid),
                   sum(s, e, node * 2 + 1, mid + 1, ne));
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    SegTree st;
    pair<int, int> p[N];
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        p[i] = make_pair(tmp, i);
    }

    // 중복 고려 할 필요가 없다.
    sort(p, p + N);

    for (auto &v : p) {
        int result = st.sum(0, v.second);
        st.update(v.second, result + 1);
    }

    cout << N - st.sum(0, st.start - 1);
}
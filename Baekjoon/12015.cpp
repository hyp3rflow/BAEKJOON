#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, tmp;
const int MAX = 1 << 21;
int arr[MAX];

struct SegTree {
    int start;

    SegTree() {
        fill(arr, arr + MAX, 0);
        start = MAX / 2;
    }

    void init() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    }

    void update(int idx, int value) {
        arr[start + idx] = value;
        for (int i = (start + idx) / 2; i > 0; i /= 2) {
            arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
        }
    }

    int sum(int s, int e) { return sum(s, e, 1, 0, start); }
    int sum(int s, int e, int node, int ns, int ne) {
        if (e <= ns || ne <= s)
            return 0;
        if (s <= ns && ne <= e) {
            return arr[node];
        }

        int mid = (ns + ne) / 2;
        return max(sum(s, e, node * 2, ns, mid),
                   sum(s, e, node * 2 + 1, mid, ne));
    }
};

int main() {
    cin >> N;
    pair<int, int> p[N];
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        p[i] = make_pair(tmp, i);
    }

    SegTree st;
    st.init();

    // 중복이 가능한 경우를 생각해서 값이 같은 경우에는 뒤의 인덱스에 놓인 것부터 봐주게 해야함.
    sort(p, p + N, [](pair<int, int> &p1, pair<int, int> &p2) {
        if (p1.first < p2.first)
            return true;
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return false;
    });

    for (pair<int, int> tmp : p) {
        int value = tmp.first;
        int idx = tmp.second;

        int maxx = st.sum(0, idx);
        st.update(idx, maxx + 1);
    }

    cout << st.sum(0, st.start);
}
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

int N, tmp;
const int MAX = 1 << 21;
int arr[MAX], result[MAX];

struct SegTree {
    int start = MAX / 2;
    SegTree() {
        fill(arr, arr + MAX, 1);
    }

    void init() {
        for (int i = start - 1; i > 0; i--) {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    int sum(int s, int e) {
        return sum(s, e, 1, 0, start - 1);
    }
    int sum(int s, int e, int node, int ns, int ne) {
        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e)
            return arr[node];

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

    cin >> N;
    pair<int, int> p[N];

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        p[i] = make_pair(tmp, i);
    }

    sort(p, p + N);

    SegTree st;
    st.init();
    int cnt = 0;
    while (cnt < N) {
        int currIdx = p[cnt / 2].second;
        int nextIdx = p[cnt / 2].first - 1;

        result[cnt] = st.sum(0, currIdx - 1);

        st.update(currIdx, 0);

        cnt++;
        if (cnt == N)
            break;

        currIdx = p[N - (cnt + 1) / 2].second;
        nextIdx = p[N - (cnt + 1) / 2].first - 1;

        result[cnt] = st.sum(currIdx + 1, N - 1);

        st.update(currIdx, 0);

        cnt++;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }
}
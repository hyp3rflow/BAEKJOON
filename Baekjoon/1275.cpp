#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int st_MAX = 1 << 21;
typedef long long ll;

ll arr[st_MAX];
ll N, Q, x, y, a, b;

struct SegTree
{
    int start = st_MAX / 2;

    SegTree() { fill(arr, arr + st_MAX, 0); }

    void init()
    {
        for (int i = start - 1; i > 0; i--)
        {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    ll sum(int s, int e) { return sum(s, e, 1, 0, start - 1); }
    ll sum(int s, int e, int node, int ns, int ne)
    {
        if (e < ns || ne < s)
            return 0;
        if (s <= ns && ne <= e)
        {
            return arr[node];
        }

        int mid = (ns + ne) / 2;

        return sum(s, e, node * 2, ns, mid) +
               sum(s, e, node * 2 + 1, mid + 1, ne);
    }

    void update(int idx, int value)
    {
        arr[start + idx] = value;
        for (int i = (start + idx) / 2; i > 0; i /= 2)
        {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SegTree st;

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[st.start + i];
    }

    st.init();

    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << st.sum(x - 1, y - 1) << "\n";
        st.update(a - 1, b);
    }
}
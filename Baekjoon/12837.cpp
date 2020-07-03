#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1 << 21;
ll arr[MAX];

int N, Q;
ll p, x, q;

struct SegTree
{
    int start;
    SegTree()
    {
        fill(arr, arr + MAX, 0);
        start = MAX / 2;
    }

    void init()
    {
        for (int i = start - 1; i > 0; i--)
        {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    void update(int idx, ll value)
    {
        arr[start + idx] += value;
        for (int i = (start + idx) / 2; i > 0; i /= 2)
        {
            arr[i] = arr[i * 2] + arr[i * 2 + 1];
        }
    }

    ll sum(int s, int e) { return sum(s, e, 1, 0, start - 1); }
    ll sum(int s, int e, int node, int ns, int ne)
    {
        if (e < ns || ne < s)
        {
            return 0;
        }

        if (s <= ns && ne <= e)
        {
            return arr[node];
        }

        int mid = (ns + ne) / 2;
        return sum(s, e, node * 2, ns, mid) +
               sum(s, e, node * 2 + 1, mid + 1, ne);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;

    SegTree st;
    // st.init();

    for (int i = 0; i < Q; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp == 1)
        {
            cin >> p >> x;
            st.update(p - 1, x);
        }

        if (tmp == 2)
        {
            cin >> p >> q;
            // endl 쓰면 틀림 ㅋㅋ..
            cout << st.sum(p - 1, q - 1) << "\n";
        }
    }
}

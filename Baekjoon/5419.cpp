#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int SIZE = 1<<18;
int T, N, a, b;

struct SegTree{
    int tree[SIZE];
    
    SegTree(){
        fill(tree, tree+SIZE, 0);
    }

    void increment(int n){
        n += SIZE / 2;
        while(n){
            tree[n]++;
            n /= 2;
        }
    }

    int sum(int start, int end){
        return sum(start, end, 1, 0, SIZE/2);
    }
    int sum(int start, int end, int node, int nodeStart, int nodeEnd){
        if(end <= nodeStart || nodeEnd <= start) return 0;
        if(start <= nodeStart && nodeEnd <= end) return tree[node];
        int mid = (nodeStart + nodeEnd) / 2;
        return sum(start, end, node*2, nodeStart, mid) + sum(start, end, node*2+1, mid, nodeEnd);
    }
};

int main(){
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        SegTree st;
        p point[75000];

        scanf("%d", &N);
        for(int j=0; j<N; j++){
            scanf("%d %d", &a, &b);
            point[j] = p(a, b);
        }

        sort(point, point+N, [](p &a, p &b) {
            return a.second < b.second;
        });

        int nY[75010], range = 0;
        for(int j=0; j<N; j++){
            if(j && point[j].second != point[j-1].second) range++;
            nY[j] = range; 
        }

        for(int j=0; j<N; j++){
            point[j].second = nY[j];
        }

        sort(point, point + N, [](p &a, p &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        ll res = 0;
        for(int j=0; j<N; j++){
            res += st.sum(point[j].second, SIZE/2);
            st.increment(point[j].second);
        }

        printf("%lld\n", res);
    }
}
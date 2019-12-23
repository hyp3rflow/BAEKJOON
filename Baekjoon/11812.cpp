#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

#define mk make_pair

using namespace std;

typedef long long ll;
typedef pair<char, char> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;
int N, M, T, K, Q;
vector<int> inf[100010];
vector<pair<double, p>> arr;
stack<int> s;
queue<int> q;

ll parent(ll a, int k){
    return (a + k - 2)/k;
}

int main() {
    ll n;
    scanf("%lld %d %d", &n, &K, &Q);

    for(int i=0; i<Q; i++){
        ll x, y;
        int res = 0;
        scanf("%lld %lld", &x, &y);

        if(K == 1) {
            printf("%lld\n", abs(x-y));
            continue;
        }

        while (x != y){
            while (x > y){
                res++;
                x = parent(x, K);
            }
            while (x < y){
                res++;
                y = parent(y, K);
            }
        }

        printf("%d\n", res);
    }
    return 0;
}



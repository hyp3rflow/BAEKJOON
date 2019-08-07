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

typedef pair<int, int> p;
typedef pair<int, p> ip;
typedef pair<p, int> xyz;
int N, S, P;

int uf[550];
int find(int a){ //union-find fill(-1) needed
    if(uf[a] < 0) return a;
    return uf[a] = find(uf[a]);
}

bool uni(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    uf[b] = a;
    return true;
}

bool comp(pair<double, p> a, pair<double, p> b){
    if(a.first < b.first) return true;
    return false;
}

int main() {
    scanf("%d", &N);
    for(int test=0; test<N; test++){
        vector<p> inf;
        vector<pair<double, p>> arr;

        int S, P;
        scanf("%d %d", &S, &P);
        for(int i=0; i<P; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            inf.push_back(mk(x, y));
        }

        for(int i=0; i<inf.size(); i++){
            int a = inf[i].first;
            int b = inf[i].second;
            for(int j=i+1; j<inf.size(); j++){
                int m = inf[j].first;
                int n = inf[j].second;
                double dist = sqrt(pow(m-a, 2) + pow(n-b, 2));

                arr.push_back(mk(dist, mk(i, j)));
            }
        }

        sort(arr.begin(), arr.end());

        fill(uf, uf+P, -1);
        double result = 0, cnt = 0;
        for(int i=0; ;i++){
            if(uni(arr[i].second.first, arr[i].second.second)){
                result = max(result, arr[i].first);
                if(++cnt == P-S) break;
            }
        }

        printf("%.2f\n", result);
        
        inf.empty();
        arr.empty();
    }

    return 0;
}


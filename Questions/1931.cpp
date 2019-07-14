#include <iostream>
#include <utility>
#include <algorithm>


using namespace std;

int n, result = 1;
pair<int, int> p[100010];

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    cin >> n;

    for(int i=1; i<=n; i++) cin >> p[i].first >> p[i].second;

    sort(&p[1], &p[n+1], cmp);

    int tmp = p[1].second;
    for(int i=2; i<=n; i++){
        if(tmp <= p[i].first) {
            tmp = p[i].second;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}

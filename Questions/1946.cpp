#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 1000010;
pair<int, int> p[MAX];
int m, n, result;

int main(){
    cin >> m;

    for(int i=0; i<m; i++){
        result = 1; // initialize result value

        cin >> n;
        for(int j=1; j<=n; j++) cin >> p[j].first >> p[j].second;

        sort(&p[1], &p[n+1]);
        int tmp = p[1].second;

        for(int j=2; j<=n; j++) if(p[j].second < tmp) result++, tmp = p[j].second;

        cout << result << endl;
    }

    return 0;
}

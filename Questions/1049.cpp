#include <iostream>
#include <utility>

using namespace std;

int n, m, ans;
pair<int, int> str[51], result = {1010, 1010};

int main(){
    cin >> n >> m;

    for(int i=1; i<=m; i++){
        cin >> str[i].first >> str[i].second;
        result.first = min(result.first, str[i].first);
        result.second = min(result.second, str[i].second);
    }

    if(result.first >= result.second * 6) ans = result.second * n;
    else ans = min(result.first * (n/6) + result.second * (n%6), result.first * (n/6 +1));

    cout << ans << endl;
}

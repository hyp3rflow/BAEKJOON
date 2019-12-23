#include <iostream>

using namespace std;

int n, k, result;
int coin[11];

int main() {
    cin >> n >> k;

    for(int i=1; i<=n; i++) cin >> coin[i];
    for(int i=n; i; i--){
        result += k/coin[i];
        k %= coin[i];
        if(!k) break;
    }

    cout << result;

    return 0;
}

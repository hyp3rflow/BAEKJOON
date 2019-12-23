#include <iostream>
#include <vector>

using namespace std;

int n, k;
int result;

vector<int> dp[1010];

int main(){
    cin >> n >> k;

    dp[0].push_back(1);

    if(!k) result = 1;
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i].push_back(1);
                } else if (j == i) {
                    dp[i].push_back(1);
                } else {
                    dp[i].push_back((dp[i - 1][j - 1] + dp[i - 1][j])%10007);
                }
            }
        }

        result = dp[n][k];
    }

    cout << result;

    return 0;
}

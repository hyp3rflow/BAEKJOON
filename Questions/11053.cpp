#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[1010], dp[1010];
int siz;

int main(){
    cin >> siz;

    for(int i=0; i<siz; i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    dp[0] = 1;

    for(int i=1; i<siz; i++){
        int tmp = 0;
        for(int j=0; j<siz; j++){
            if(arr[i] > arr[j]) tmp = max(tmp, dp[j]);
        }
        dp[i] = tmp + 1;
    }

    int result = -1;

    for(int i=0; i<siz; i++) result = max(result, dp[i]);

    cout << result;

    return 0;
}

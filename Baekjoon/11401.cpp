#include <iostream>
using namespace std;

int n, k, result;
const int R = 1000000007;
long factorial[4000010] = {1, 1};

int main(){
    cin >> n >> k;

    for(int i=2; i<=n; i++){
        factorial[i] = (factorial[i-1] * i) % R;
    }

    long tmp = (factorial[k] * factorial[n-k]) % R;
    long val = 1;

    int cnt = R-2;
    while(cnt > 0){
        if(cnt % 2 == 1) val *= tmp, val %= R;
        tmp = (tmp * tmp) % R;
        cnt /= 2;
    }

    result = (factorial[n] * val % R) % R;

    cout << result;
}

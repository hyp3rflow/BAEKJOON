#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long b, arr[6][6], tmp[6][6], ans[6][6];

void mt(long long x[][6], long long y[][6]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = 0;
            for(int k=0; k<n; k++) tmp[i][j] += x[i][k] * y[k][j];
            tmp[i][j] %= 1000;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) x[i][j] = tmp[i][j];
    }
}

int main(){
    cin >> n >> b;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) ans[i][i] = 1;

    while(b > 0){
        if(b % 2 == 1) mt(ans, arr);
        mt(arr, arr);
        b /= 2;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}


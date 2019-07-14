#include <iostream>
#include <cmath>

using namespace std;

int n, m, k;

void ant(int len, int siz, int arr[1000010]){
    int minn = 10000000;
    float maxx = float(len)/2;
    for(int i=0; i<siz; i++){
        if(abs(float(len)/2 - minn) > abs(float(len)/2 - arr[i])) minn = arr[i];
        if(abs(float(len)/2 - maxx) < abs(float(len)/2 - arr[i])) maxx = arr[i];
    }
    
    cout << min(minn, len-minn) << " " << max(maxx, len-maxx) << endl;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> m >> k;
        int arr[1000010] = {0};
        for(int j=0; j<k; j++) cin >> arr[j];
        ant(m, k, arr);
    }
    
    return 0;
}

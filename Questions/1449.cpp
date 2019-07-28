#include <iostream>
#include <algorithm>

using namespace std;

int N, L, k, tmp, cnt;
int arr[1010];

int main(){
    cin >> N >> L;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    for(int i=0; i<N; i++){
        if(tmp == 0){
            tmp = arr[i];
            cnt++;
        }
        else{
            if(tmp + L - 1 >= arr[i]);
            else{
                tmp = arr[i];
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
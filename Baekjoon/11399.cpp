#include <iostream>
#include <algorithm>

using namespace std;

int n, tmp, result, arr[1010];

int main(){
    cin >> n;

    for(int i=1; i<=n; i++) cin >> arr[i];

    sort(arr+1, arr+n+1);

    for(int i=1; i<=n; i++) tmp += arr[i], result += tmp;

    cout << result << endl;

    return 0;
}


#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

const long R = 1000000007;
unsigned long long m, n, ans = 1;
unsigned long long arr[70];
stack<int> st;

int main(){
    cin >> m >> n;

    for(int i=0; i < 70; i++){
        if(n%2) st.push(1);
        else st.push(0);
        n /= 2;
        if(!n) break;
    }

    arr[0] = m%R;
    for(int i=1; i<st.size(); i++){
        arr[i] = arr[i-1] * arr[i-1] % R;
    }

    while(!st.empty()){
        int tmp = st.size() - 1;
        int chk = st.top();
        if(chk) ans *= arr[tmp];
        st.pop();
        if(ans >= R) ans %= R;
    }

    cout << ans;

    return 0;
}

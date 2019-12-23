#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long n;
int fib[1500000] = {0, 1, 1}, result;
const int R = 1000000;
const int period = 1500000;

int main(){
    cin >> n;

    for(int i=3; i<period; i++){
        fib[i] = (fib[i-1] + fib[i-2])%R;
    }

    result = fib[n%period];

    cout << result << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    for (int i = 1000; i; i--) cout << "1 ";
    for (int i = 1; i <= 1000; i++) {
        cout << 1000;
        if (i != 1000) cout << " ";
    }
    
    return 0;
}

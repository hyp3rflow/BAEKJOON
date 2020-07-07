#include <iostream>

using namespace std;

int x1, y1, x2, y2, x3, y3;

int cross(int a, int b, int c, int d) {
    return a * d - c * b;
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result = cross(x2 - x1, x3 - x2, y2 - y1, y3 - y2);
    if (result > 0)
        cout << 1;
    if (result < 0)
        cout << -1;
    if (result == 0)
        cout << 0;
    return 0;
}
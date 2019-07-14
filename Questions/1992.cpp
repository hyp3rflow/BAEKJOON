#include <iostream>
using namespace std;

const int MAX = 64;
int arr[MAX][MAX], n;
char str[MAX+1];

void quad(int siz, int x, int y){
    if(siz == 1){
        cout << arr[x][y];
        return;
    }

    bool tmp = true;
    for(int i=y; i<y+siz; i++){
        if(!tmp) break;
        for(int j=x; j<x+siz; j++){
            if(arr[x][y] != arr[j][i]){
                tmp = false;
                break;
            }
        }
    }

    if(tmp){
        cout << arr[x][y];
        return;
    }

    int siztmp = siz/2;

    cout << '(';
    quad(siztmp, x, y);
    quad(siztmp, x, y+siztmp);
    quad(siztmp, x+siztmp, y);
    quad(siztmp, x + siztmp, y + siztmp);
    cout << ')';
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=n; j; j--){
            arr[i][j-1] = str[j-1] - '0';
        }
    }

    quad(n, 0, 0);

    return 0;
}

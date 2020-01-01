#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[2188][2188];
int cnt[3];

void func(int x, int y, int size){
    int crit = arr[x][y];
    bool state = true;

    for (int i = 0; i < size; i++){
        if(!state){
            break;
        }
        for (int j = 0; j < size; j++){
            if(crit != arr[x+i][y+j]){
                state = false;
                break;
            }
        }
    }

    if(state){
        cnt[crit + 1]++;
    }
    else{
        int newSize = size / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++){
                func(x + newSize * i, y + newSize * j, newSize);
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf(" %d", &arr[i][j]);
        }
    }

    func(1, 1, N);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", cnt[i]);

    }
}
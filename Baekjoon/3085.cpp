#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int N;
char arr[55][55];
int result = -1;

int check() {
    int maxx = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            char curr = arr[i][j];
            int m = i, n = j;
            while (m < N && n < N) {
                if (curr == arr[m][n]) {
                    cnt++;
                    m++;
                } else {
                    break;
                }
            }
            maxx = max(cnt, maxx);
            cnt = 0;
            m = i, n = j;
            while (m < N && n < N) {
                if (curr == arr[m][n]) {
                    n++;
                    cnt++;
                } else {
                    break;
                }
            }
            maxx = max(cnt, maxx);
        }
    }

    return maxx;
}

int main() {
    scanf("%d", &N);

    char tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    result = max(result, check());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < N - 1) {
                swap(arr[i][j], arr[i + 1][j]);
                result = max(result, check());
                swap(arr[i][j], arr[i + 1][j]);
            }
            if (j < N - 1) {
                swap(arr[i][j], arr[i][j + 1]);
                result = max(result, check());
                swap(arr[i][j], arr[i][j + 1]);
            }
        }
    }

    printf("%d", result);
}
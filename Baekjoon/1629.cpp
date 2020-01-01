#include <cstdio>
#include <algorithm>

using namespace std;

long long A, B, C;

long long pow(long long num, long long cnt, long long div){
    if(cnt == 0) return 1;
    if(cnt % 2){
        long long tmp = pow(num, cnt/2, div);
        return (num * (((tmp % div) * (tmp % div)) % div)) % div;
    } else {
        long long tmp = pow(num, cnt/2, div);
        return ((tmp % div) * (tmp % div)) % div;
    }
}


int main(){
    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld", pow(A%C, B, C) % C);
}
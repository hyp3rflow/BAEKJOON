#include <stdio.h>

int main(){
    int st[100000];
    int stcnt = -1;
    int in;
    int tmp;
    int cnt = 1;
    int result[300000];
    int recnt = 0;
    int s = 1;

    scanf(" %d", &in);
    
    while(in--){
        scanf(" %d", &tmp);
if(s){
        // when stack is empty
        if(stcnt == -1){
            if(cnt > tmp){
                s = 0;
                continue;
            }
            else{
                while(cnt <= tmp){
                    st[++stcnt] = cnt++;
                    result[recnt++] = 1; // push
                }
                result[recnt++] = 0; // pop
                stcnt--;
            }
        }
        else if(cnt > tmp){
            if(st[stcnt] == tmp){
                stcnt--;
                result[recnt++] = 0;
            }
            else{
                s = 0;
                continue;
            }
        }
        else if(cnt <= tmp){
            while(cnt <= tmp){
                st[++stcnt] = cnt++;
                result[recnt++] = 1;
            }
            result[recnt++] = 0;
            stcnt--;
        }
}
    }

    if(s){
    for(int i=0; i<recnt; i++){
        result[i] ? printf("+") : printf("-");
        printf("\n");
    }
    }
    else{
        printf("NO");
    }
}

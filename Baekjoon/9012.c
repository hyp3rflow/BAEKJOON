#include <stdio.h>

int main(){
    char input[51];
    int result[100];
    int siz, tmp;
    int cnt = 0, flag, recnt = 0;
    
    scanf(" %d", &siz);
    
    tmp = siz;

    while(siz--){
        scanf(" %s", input);

        cnt = 0;
        flag = 1;
        for(int i=0; input[i]; i++){
            if(input[i] == '('){
                cnt++;
            }
            else{
                cnt--;
                if(cnt < 0){
                    result[recnt++] = 0;
                    flag = 0;
                    break;
                }
            }
        }
        if(cnt != 0 && flag){
            result[recnt++] = 0;
        }
        else if(flag){
            result[recnt++] = 1;
        }
    }

    for(int i=0; i<recnt; i++){
        result[i] ? printf("YES\n") : printf("NO\n");
    }
}

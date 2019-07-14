#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int stack[10000];
    int m, cnt = 0;
    char od[13];
    char *ptr;

    scanf("%d", &m);
    getchar();

    for(int i=0; i<m; i++){
        fgets(od, 13, stdin);
        if(!strcmp(od, "empty\n")){
            if(cnt){
                printf("0\n");
            }
            else{
                printf("1\n");
            }
        }
        else if(!strcmp(od, "pop\n")){
            if(!cnt){
                printf("-1\n");
            }
            else{
                printf("%d\n", stack[cnt-1]);
                cnt--;
            }
        }
        else if(!strcmp(od, "top\n")){
            if(!cnt){
                printf("-1\n");
            }
            else{
                printf("%d\n", stack[cnt-1]);
            }
        }
        else if(!strcmp(od, "size\n")){
            printf("%d\n", cnt);
        }
        else{
            ptr = &od[5];
            stack[cnt] = atoi(ptr);
            cnt++;
        }
    }

    return 0;
}

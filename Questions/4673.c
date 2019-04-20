#include <stdio.h>

void is_self_number(int num){
  int cpy, sum;
  int cnt = 0;
  for(int i = 1; i < num; i++){
     cpy = i;
     sum = i;
     while(cpy != 0){
       sum += cpy % 10;
       cpy /= 10;
     }
     if (num == sum){
      cnt++;
     }
   }
  if(cnt == 0){
    printf("%d\n", num);
  }
}

int main(){
  for(int i = 1; i <= 10000; i++){
    is_self_number(i);
  }

  return 0;
}


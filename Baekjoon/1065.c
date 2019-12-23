#include <stdio.h>

void hansoo(int n){
  int deungcha;
  int tmp;
  int cnt = 0;
  int numofhansoo = 0;
  for(int i = 1; i <= n; i++){
    tmp = i;
    deungcha = tmp%10 - (tmp%100)/10;
    while(tmp / 10 != 0){
      if(tmp%10 - (tmp%100)/10 == deungcha){
        tmp /= 10;
        continue;
      } 
      cnt++;
      break;
    }
    if(cnt == 0){
      numofhansoo++;
    }
    cnt = 0;
  }
  printf("%d", numofhansoo);
}

int main(){
  int input;
  scanf("%d", &input);

  hansoo(input);
}

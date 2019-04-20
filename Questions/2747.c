// BAEKJOON #2747
// Fibonacci number

#include <stdio.h>

int main(){
  int input;
  int a = 0, b = 1, tmp;

  scanf("%d", &input);

  if(input == 0 || input == 1){
    printf("%d", input);
  }
  else{
    while(input > 1){
      tmp = b;
      b += a;
      a = tmp;

      input--;
    }

    printf("%d", b);
  }
}

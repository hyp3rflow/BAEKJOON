#include <stdio.h>

int main(){
  long long a = 0, b = 1, tmp;
  long long input;

  scanf("%lld", &input);

  if(input == 0 || input == 1){
    printf("%lld", input);
  }
  else{
    while(input > 1){
      tmp = b;
      b += a;
      a = tmp;

      input--;
    }

    printf("%lld", b%1000000);
  }
}

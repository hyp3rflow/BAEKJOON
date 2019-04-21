#include <stdio.h>

void binary(int n);

int main(void){
  int n;
  
  scanf("%d", &n);

  binary(n);

  return 0;
}

void binary(int n){
  if(n>1){
    if(n % 2 == 0){
      binary(n/2);
      printf("0");
    }
    else{
     binary(n/2);
     printf("1");
    }
  }
  else{
    printf("%d", n);
  }

}

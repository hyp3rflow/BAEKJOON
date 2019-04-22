#include <stdio.h>

void g(int x){
  static int y = 3;
  y++;
  printf("y: %d\n", y);
  x += 5;
  printf("%d \n", x);
}


int main(){
  static int x = 5;
  g(x);
  g(x);
  g(x);

  printf("%d", x);
}

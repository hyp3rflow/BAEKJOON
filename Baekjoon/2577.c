#include <stdio.h>

int main(){
  int a, b, c;
  int sum;
  int cnt = 0;
  
  int numbers[10] = {0};

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  sum = a*b*c;

  for(; sum; sum/=10){
    numbers[sum%10]++;
  }

  for(int i = 0; i<10; i++){
    printf("%d\n", numbers[i]);
  }

  return 0;
}

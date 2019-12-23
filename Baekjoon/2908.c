#include <stdio.h>

int main(){
  int input1, input2;
  int tmp;
  scanf("%d %d", &input1, &input2);

  tmp = 0;

  for(;input1;input1/=10){
    tmp *= 10;
    tmp += input1%10;
  }
  
  input1 = tmp;

  tmp = 0;

  for(;input2;input2/=10){
    tmp *= 10;
    tmp += input2%10;
  }
  
  input2 = tmp;

  if(input1 > input2){
    printf("%d", input1);
  }
  else{
    printf("%d", input2);
  }

  return 0;
}

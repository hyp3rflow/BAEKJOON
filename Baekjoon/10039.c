#include <stdio.h>

int main(){
  int array[6] = {0};
  
  for(int i=0; i<5; i++){
    scanf("%d", &array[i]);
    if(array[i] >= 40){
      array[5] += array[i];
    }
    else{
      array[5] += 40;
      array[i] = 40;
    }
  }

  array[5] /= 5;
  printf("%d", array[5]);

  return 0;
}

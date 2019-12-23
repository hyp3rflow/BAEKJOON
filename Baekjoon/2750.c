#include <stdio.h>

int main(){
  int array[1000];
  int cnt, tmp;
  
  scanf("%d", &cnt);

  for(int i = 0; i < cnt; i++){
    scanf("%d", &array[i]);
  }

  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < cnt - 1; j++){
      if(array[j] > array[j+1]){
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }

  for(int i = 0; i < cnt; i++){
    printf("%d\n", array[i]);
  }

  return 0;
}

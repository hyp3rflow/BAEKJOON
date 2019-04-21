#include <stdio.h>

void bubblesort(int array[], int cnt){
  int tmp;
  for(int i = 0; i < cnt; i++){
    for(int j = 0; j < cnt-1; j++){
      if(array[j] > array[j+1]){
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }
}

int main(){
  int n[99];

  int cnt, col;
  
  scanf("%d %d", &cnt, &col);

  for(int i = 0; i < cnt; i++){
    scanf("%d", &n[i]);
  }

  bubblesort(n, cnt);

  for(int a = 0; a < cnt; a++){
    printf("%d ", n[a]);
    if((a+1)%col == 0){
      printf("\n");
    }
  }

  return 0;
}

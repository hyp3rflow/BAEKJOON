#include <stdio.h>

int main(){
  
  int array[8];
  int finder = 0;
  
  for(int i = 0; i < 8; i++){
    scanf("%d", &array[i]);  
  }
  
  for(int j = 0; j < 7; j++){
  
    if(array[j] - array[j+1] < 0){
      finder++;
    }
    else if(array[j] - array[j+1] > 0){
      finder--;
    }
  }
  
  if(finder == 7){
    printf("ascending");
  }
  else if(finder == -7){
    printf("descending");
  }
  else{
    printf("mixed");
  }

  return 0;
}

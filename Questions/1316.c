#include <stdio.h>

int main(void){
  int wordcnt = 0, cnt, sum = 0;
  char input[100];

  scanf("%d", &cnt);

  while(cnt != 0){
    scanf("%s", input);
    
    for(int i = 0; input[i]; i++){
      while(input[i] == input[i+1]){
        for(int j = 0; input[i+j]; j++){
          input[i+j] = input[i+j+1];
        }
      }
    }
    
    for(int i = 0; input[i]; i++){
      for(int j = i+1; input[j]; j++){
        if(input[i] == input[j]){
          wordcnt += 1;
        }
      }
    }

    if(wordcnt == 0){
      sum += 1;
    }

    wordcnt = 0;

    cnt--;
  }

  printf("%d", sum);
}

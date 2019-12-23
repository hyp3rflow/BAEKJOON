#include <stdio.h>

int main(){
  int input;
  int score = 1, sum = 0;

  char string[80];

  scanf("%d", &input);

  for(int i = 0; i<input; i++){
    scanf("%s", string);

    for(int k = 0; string[k]; k++){
     
      if(string[k] == 'O'){
        
        sum += score;
      
        if(string[k+1] == 'O'){
          score++;
        }
        else{
          score = 1;
        }
      
      }
    
    }
  
    printf("%d\n", sum);
    sum = 0;
  }

}

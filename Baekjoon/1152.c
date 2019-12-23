#include <stdio.h>

int main(){
  char line[1000000];
  int cnt = 0;
  int last;

  gets(line);
  
  for(int i = 0; line[i]; i++){
    if(line[i] == ' '){
      cnt++;
    }
    if(line[i+1] == 0){
      last = i+1;
    }
  }

  if(line[0] == ' '){
    cnt--;
  }

  if(line[last-1] == ' '){
    cnt--;
  }

  printf("%d", cnt+1);

  return 0;
}

#include <stdio.h>
#include <string.h>

int main(){
  char arr[100];
  char *ptr;
  char result[100];
  int cnt = 0;

  scanf("%s", arr);

  ptr = strtok(arr, "-");
  while(ptr){
    result[cnt] = *ptr;
    cnt++;
    ptr = strtok(NULL, "-");
  }

  result[cnt] = '\0';

  printf("%s", result);
}

#include <stdio.h>

int min(int a, int b, int c);
int algorithm(int i);

int arr[1000000];

int main(){
  int i, cnt = 0;

  scanf("%d", &i);

  printf("%d\n\n", algorithm(i));

  return 0;
}

int algorithm(int i){
  if(arr[i]) return arr[i];

  int tmp;
  
  if(i == 1){
    return 0;
  }

  if(i%3 == 0 && i%2 == 0){
    tmp = min(algorithm(i/3), algorithm(i/2), algorithm(i-1)) + 1;
    arr[i] = tmp;
    return tmp;
  }
  if(i%3 == 0){
    tmp = min(algorithm(i/3), algorithm(i-1), -1) + 1;
    arr[i] = tmp;
    return tmp;
  }
  if(i%2 == 0){
    tmp = min(algorithm(i/2), algorithm(i-1), -1) + 1;
    arr[i] = tmp;
    return tmp;
  }
  tmp = algorithm(i-1) + 1;
  arr[i] = tmp;
  return tmp;
}

int min(int a, int b, int c){
  int arr[3] = {a, b, c};
  int mini = arr[0];
  for(int i=1; i<3; i++){
    if(arr[i] == -1){
      continue;
    }
    if(mini > arr[i]){
      mini = arr[i];
    }
  }
  return mini;
}

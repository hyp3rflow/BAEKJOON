#include <stdio.h>

void quicksort(int n, int arr[]);

int main(){
  int cnt[10000] = {0};
  int n;
  int tmp;

  scanf("%d", &n);

  for(int i = 0; i<n; i++){
    scanf("%d", &tmp);
    cnt[tmp-1]++;
  }

  quicksort(n, cnt);

  return 0;
}

void quicksort(int n, int arr[]){
  for(int i = 0, cnt = 0; cnt<n; i++){
    for(int j = 0; j<arr[i]; j++){
      printf("%d\n", i+1);
      cnt++;
    }
  }
}

#include <stdio.h>

void mergesort(int start, int end, int array[], int sorted[]);
void merge(int start, int mid, int end, int array[], int sorted[]);

int main(){
  int cnt;
  int array[1000000];
  int sorted[1000000];

  scanf("%d", &cnt);

  for(int i = 0; i < cnt; i++){
    scanf("%d", &array[i]);
  }

  mergesort(0, cnt-1, array, sorted);

  for(int i = 0; i < cnt; i++){
    printf("%d\n", array[i]);
  }

  return 0;
}

void mergesort(int start, int end, int array[], int sorted[]){
  int mid = (start+end)/2;
  if(start != end){
    mergesort(start, mid, array, sorted);
    mergesort(mid+1, end, array, sorted);
    merge(start, mid, end, array, sorted);
  }
}

void merge(int start, int mid, int end, int array[], int sorted[]){
  int i, j, k, l;
  i = start;
  j = mid+1;
  k = end;
  l = start;

  while(i<=mid && j<=end){
    sorted[l++] = (array[i] > array[j]) ? array[j++] : array[i++];
  }

  if(i > mid){
    for(; j<=end; j++){
      sorted[l++] = array[j];
    }
  }
  else{
    for(; i<=mid; i++){
      sorted[l++] = array[i];
    }
  }

  for(int cnt = start; cnt <= end; cnt++){
    array[cnt] = sorted[cnt];
  }
}

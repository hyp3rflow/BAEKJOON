#include <stdio.h>

void snail(int n, int array[][50], int startrow, int startcol, int endrow, int endcol);

int main(){
  int n;
  int startrow, startcol, endrow, endcol;

  int array[50][50];
  
  scanf("%d", &n);

  startrow = 0;
  startcol = 0;
  endrow = n - 1;
  endcol = n - 1;
  if(n == 1){
    printf("%d", 1);
  }
  else{
  snail(n, array, startrow, startcol, endrow, endcol);
  

  for(int i = 0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  }
  return 0;
}

void snail(int n, int array[][50], int startrow, int startcol, int endrow, int endcol){
  static int cnt = 1;

  for(int col = startcol; col < endcol; col++){
    array[startrow][col] = cnt++;
  }

  for(int row = startrow; row < endrow; row++){
    array[row][endcol] = cnt++;
  }

  for(int col = endcol; startcol < col; col--){
    array[endrow][col] = cnt++;
  }

  for(int row = endrow; startrow < row; row--){
    array[row][startcol] = cnt++;
  }

  if(cnt == n*n){
    array[startrow+1][startcol+1] = cnt;
  }
  else if(cnt < n*n){
    snail(n, array, startrow+1, startcol+1, endrow-1, endcol-1);
  }
}

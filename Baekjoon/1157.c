#include <stdio.h>

int main(){
  char input[1000000];
  int alphabet[26] = {0};
  int maxvalue = 0;
  char maxchar = 0::;

  scanf("%s", input);

  for(int i = 0; input[i]; i++){
    if(input[i] >= 'a' && input[i] <= 'z'){
      alphabet[input[i]-'a']++;
    }
    else if(input[i] >= 'A' && input[i] <= 'Z'){
      alphabet[input[i]-'A']++;
    }
  }

  for(int j=0; j<26; j++){
    if(alphabet[j] > maxvalue){
      maxchar = j;
      maxvalue = alphabet[j];
    }
    else if(alphabet[j] == maxvalue){
      maxchar = '?'-'A';
    }
  }

  printf("%c", maxchar+'A');

  return 0;
}

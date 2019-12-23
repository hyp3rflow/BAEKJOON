#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>

#define mk make_pair

using namespace std;

typedef pair<char, char> p;
typedef pair<int, p> ip;
int N, M;
vector<p> inf[27];

void preOrder(char root){
    char left = inf[root-'A'].front().first;
    char right = inf[root-'A'].front().second;

    printf("%c", root);
    if(left != '.') preOrder(left);
    if(right != '.') preOrder(right);
}

void inOrder(char root){
    char left = inf[root-'A'].front().first;
    char right = inf[root-'A'].front().second;

    if(left != '.') inOrder(left);
    printf("%c", root);
    if(right != '.') inOrder(right);
}

void postOrder(char root){
    char left = inf[root-'A'].front().first;
    char right = inf[root-'A'].front().second;

    if(left != '.') postOrder(left);
    if(right != '.') postOrder(right);
    printf("%c", root);
}

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        inf[a-'A'].push_back(mk(b, c));
    }

    preOrder('A');
    printf("\n");
    inOrder('A');
    printf("\n");
    postOrder('A');
    printf("\n");

    return 0;
}

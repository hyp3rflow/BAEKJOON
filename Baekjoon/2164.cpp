#include <iostream>
#include <deque>

using namespace std;

int input;

deque<int> dq;

int func(int input){
    for(int i=1; i <= input; i++){
        dq.push_back(i);
    }
    while(dq.size() > 1){
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }

    return dq.front();
}

int main(){
    cin >> input;
    cout << func(input);
}

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int func(string& str){
    stack<char> st;
    int result = 0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(') st.push(str[i]);
        else{
            st.pop();
            if(str[i-1] == '(') result += st.size();
            else result++;
        }
    }

    return result;
}

int main(){
    cin >> str;
    cout << func(str);
}

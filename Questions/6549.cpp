#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int n, cnt;
unsigned long long tmp;
unsigned long long maxx;
pair<unsigned long long, int> pairtmp;
stack<pair<unsigned long long, int>> st;

int main(){
    while(1) {
        cin >> n;

        maxx = 0;

        if(n != 0) {
            for (int i = 0; i < n; i++) {
                cin >> tmp;
                cnt = i;

                if (st.empty()) {
                    st.push(make_pair(tmp, i));
                } else {
                    if (st.top().first > tmp) {
                        while (!st.empty() && st.top().first > tmp) {
                            pairtmp = st.top();
                            maxx = max(pairtmp.first * (i - pairtmp.second), maxx);
                            st.pop();
                            cnt = pairtmp.second;
                        }
                    }
                    st.push(make_pair(tmp, cnt));
                }
            }

            while(!st.empty()){
                pairtmp = st.top();
                maxx = max(pairtmp.first * (n - pairtmp.second), maxx);
                st.pop();
            }

            cout << maxx << endl;

        } else {
            break;
        }
    }

    return 0;
}


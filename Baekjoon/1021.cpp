#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int N, M;
deque<int> dq;

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }

    int minn = 0;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        scanf(" %d", &tmp);
        for (int j = 0; j < dq.size(); j++)
        {
            if(dq[j] == tmp){
                int left = j;
                int right = dq.size() - j;

                if(left <= right){
                    for (int k = 0; k < left; k++){
                        dq.push_back(dq.front());
                        dq.pop_front();
                    }
                    dq.pop_front();
                }
                else{
                    for (int k = 0; k < right; k++){
                        dq.push_front(dq.back());
                        dq.pop_back();
                    }
                    dq.pop_front();
                }

                minn += min(left, right);
                break;
            }
        }
    }

    printf("%d", minn);
}
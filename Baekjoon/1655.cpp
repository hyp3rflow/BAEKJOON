#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, tmp;
priority_queue<int, vector<int>, less<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &tmp);

        if (maxheap.size() == minheap.size())
            maxheap.push(tmp);
        else
            minheap.push(tmp);

        // 가운데를 중심으로 맥스힙 / 민힙 해서 맥스힙의 탑 == 중간값
        if(minheap.size() && maxheap.top() > minheap.top()){
            int maxtmp, mintmp;
            maxtmp = maxheap.top();
            mintmp = minheap.top();

            maxheap.pop();
            minheap.pop();

            maxheap.push(mintmp);
            minheap.push(maxtmp);
        }

        printf("%d\n", maxheap.top());
    }

    return 0;
}

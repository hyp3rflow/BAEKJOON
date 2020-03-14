#include <iostream>
using namespace std;
#define ll long long
bool nums[1100000];
bool erat[1100000]; //false : prime

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    ll n1, n2, cnt = 0;
    cin >> n1 >> n2;
    //cout << "TEST A\n";
    for (ll i = 2; i * i <= n2; i++)
    {
        if (erat[i])
            continue;
        // cout << "CHECK " << i << '\n';
        for (ll j = i; j * j <= n2; j += i)
        {
            // cout << "1st for " << j << endl;
            //if(j > 999900) cout << "CHECK - J " << j << '\n';
            erat[j] = true;
        }
        for (ll j = ((n1 - 1) / (i * i) + 1) * (i * i); j <= n2; j += i * i)
        {
            // cout << "2nd for " << j << endl;
            if (!nums[j - n1])
            {
                nums[j - n1] = true;
                cnt++;
            }
        }
    }
    cout << n2 - n1 + 1 - cnt;
}
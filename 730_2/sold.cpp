#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t=1;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int p=0;
        for(int i=0;i<n;i++)
        {
            int q=p^i;
            cout << q << endl;
            p=p^q;
            int v;
            cin >> v;
            if(v==1)
                break;
        }
    }
    return 0;
}
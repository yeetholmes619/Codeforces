#include<bits/stdc++.h>
#define pb push_back
using namespace std;
long long block;

struct Query{
        int L,R,index;
};

bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;

    // Same block, sort by R value
    return x.R < y.R;
}

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        string a;
        long long n,q,l,r;
        cin>>n>>q;
        cin>>a;
        a = "$" + a;
        long long arr[q];
        Query qq[q],qqq[q];
        for(int lam = 0; lam < q; lam++){
                cin>>qq[lam].L>>qq[lam].R;
                //qq[lam].L = qqq[lam].L;
                //qq[lam].R = qqq[lam].R;
                qq[lam].index = lam;
        }
        //qq = qqq;
        block = (long long)sqrt(n);
        sort(qq,qq+q,compare);

        int currL = 0, currR = 0;
    long long currSum = 0;

    // Traverse through all queries
    for (int i=0; i<q; i++)
    {
        // L and R values of current range
        int L = qq[i].L, R = qq[i].R;

        int pos = qq[i].index;
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            currSum -= a[currL] - 'a' + 1;
            currL++;
        }

        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1] - 'a'+1;
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR] -'a' +1;
            currR++;
        }

        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            currSum -= a[currR-1] -'a' +1;
            currR--;
        }

        // Print sum of current range
        //cout << "Sum of [" << L << ", " << R
          //   << "] is "  << currSum << endl;
          arr[pos] = currSum;
    }

    for(auto t: arr){
            cout<<t<<endl;
    }
                
}

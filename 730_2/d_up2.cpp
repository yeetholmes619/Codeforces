#include<bits/stdc++.h>
using namespace std;

int main(){
        int t;
        cin>>t;
        while(t--){
                int n,k;
                cin>>n>>k;

                int p = 0;
                int q;
                int r = 0;
                int i = 0;

                while(r == 0){
                        q = p^i;
                        cout<<q<<endl;
                        cin>>r;
                        p ^= q;
                        i++;
                }
        }
}

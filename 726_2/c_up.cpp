#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve(){
        int n;
        cin>>n;
        vector<ll> v(n);
        for(auto &t : v) cin>>t;

        ll mini = (1e9)+1;
        
        sort(v.begin(),v.end());

        ll minia,minib;
        for(int i = 0; i < n-1; i++){
                if(v[i+1] - v[i] < mini){
                        mini = v[i+1] - v[i];
                        minia = i;
                        minib = i+1;
                }
        }

        vector<ll> ans;
        ans.pb(v[minia]);
        for(int i = minib+1; i < n; i++){
                ans.pb(v[i]);
        }
        
        for(int i  = 0; i < minia; i++){
                ans.pb(v[i]);
        }

        ans.pb(v[minib]);

        for(auto t: ans) cout<<t<<" ";
        cout<<"\n";

        return;
}

int main(){
        int t;
        cin>>t;
        for(int i = 0; i < t; i++){
                solve();
        }
}

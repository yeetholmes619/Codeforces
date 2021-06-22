#include<bits/stdc++.h>
using namespace std;
int log(int a,int b){
        return (int)((((log(a)))/((log(b)))));
}
void solve(){
        int n;
        cin>>n;
        if(n%2 == 1){
                cout<<"Bob"<<endl;
                return;
        }
        if(__builtin_popcount(n) == 1){
                int cnt = 0;
                while(n!=1){
                        n /= 2;
                        cnt++;
                }
                if(cnt%2 == 1){
                        cout<<"Bob"<<endl;
                        return;
                }
        }
        cout<<"Alice"<<endl;
}
int main(){
        int t;
        cin>>t;
        while(t--) solve();
}

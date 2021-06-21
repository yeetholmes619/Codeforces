#include<bits/stdc++.h>
using namespace std;



void solve(){
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s; 
        bool check = false;
        for(int i = 0; i < n; i++){
                if(s[i] > s[0]){
                        s = s.substr(0,i);
                        break;
                }
                if(i != 1){
                        if(s[i] != s[i-1]) check = true;
                }
        }

        if(check == false) goto lb;

        n = s.size();

        for(long long i = 1; i < n; i++){
                if(s[i] == s[0]){
                       // long long sie = min(i,n-i);
                       // if(s.substr(0,sie) <= s.substr(i,sie)) s = s.substr(0,i);
                       bool flag = false;
                       string s1 = s.substr(0,i);
                       long long j = 0;
                       while(j <= lcm(n,i) + 1){
                               if(s1[j%i] > s[j%n]){
                                       break;
                               }
                               if(s1[j%i] < s[j%n]){
                                       s = s1;
                                       flag = true;
                                       break;
                               }
                               j++;
                       }
                       if(flag) break;
                }
        }
lb:
        while(s.size() < k){
                s += s;
        }

        s = s.substr(0,k);

        cout<<s<<"\n";
}

int main(){
        solve();
}

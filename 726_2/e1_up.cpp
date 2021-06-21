#include<bits/stdc++.h>
using namespace std;

void solve(){
        int n,k;
        
        //vector<string> ans;

        cin>>n>>k;
        string str;
        cin>>str;
        string answer  = "";
        for(int i = 0; i < k; i++) answer += str[0];
        while(str.size() != 0){
                string s = str;
                while(s.size() < k){
                        s += s;
                }

                s = s.substr(0,k);
                answer = min(s,answer);
                str.pop_back();
        }

        cout<<answer;


}

int main(){
        //int t;
        //cin>>t;
        //for(int i = 0; i < t; i++){
                solve();
        //}
}

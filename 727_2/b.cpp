#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        string ans;
        long long n,q,l,r;
        cin>>n>>q;
        cin>>ans;
        ans = "$" + ans;
        for(int i = 0; i < q; i++){
                cin>>l>>r;
                long long answer = 0;
                long long same = 1;
                long long diff = 1;
                char letter;
                if(l==r) {
                        cout<<(1+ans[l]-'a')<<"\n";
                        continue;
                }
                for(int j = l; j < r; j++){
                        if(l==r) {
                                answer = (1+ans[j]-'a');
                                break;
                        }
                        else if(ans[j] == ans[j+1]){
                                same += 1;
                                letter = ans[j];
                                if(j == r-1){
                                        answer += same*(1+letter-'a');
                                }
                        }

                        else if(ans[j] != ans[j+1]){
                                letter = ans[j];
                                answer += same*(1+letter-'a');
                                same  = 1;
                                //diff += 1;
                                if(j == r-1)
                                answer += same*(1+ans[r]-'a');
                        }
                }
                cout<<answer<<"\n";
        }

                
}

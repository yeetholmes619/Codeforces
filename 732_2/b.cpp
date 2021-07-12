#include<bits/stdc++.h>
using namespace std;

int main(){
        int t;
        cin>>t;
        while(t--){
                int n,m;
                cin>>n>>m;

                vector<int> a(m,0);
                vector<int> b(m,0);

                for(int i = 0; i < n; i++){
                        string s;
                        cin>>s;
                        for(int i = 0; i < m;i++){
                                a[i] += abs((int)(s[i] - 'a'));
                        }
                }
                for(int i = 0; i < n-1; i++){
                        string s;
                        cin>>s;
                        for(int i = 0; i < m;i++){
                                b[i] += abs((int)(s[i] - 'a'));
                        }
                }

                for(int i = 0; i < m; i++){
                        b[i] = abs(a[i] - b[i]);
                }

                string ans = "";

                for(int i = 0; i < m; i++){
                        ans += char(b[i] + 'a');
                }
                cout<<ans<<endl;
        }
}


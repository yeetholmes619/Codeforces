#include<bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        for(int i = 0; i < t; i++){
                int n;
                cin>>n;
                int k;
                cin>>k;
                int cache = 0;
                cout<<cache<<endl;
                int response;
                cin>>response;
                if(response == 0){
                        continue;
                }

                for(int j = 1; j<n; j++){
                        cout<<j<<endl;
                        cin>>response;
                        if(response == cache){
                                break;
                        }
                        cache ^= j;
                }
        }

        return 0;
}

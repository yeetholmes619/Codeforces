#include<bits/stdc++.h>
using namespace std;

int main(){
        int l = 1, r = 1e6;
        string in;
        int mid;
        while(l != r){
                mid = (l + r + 1)/2;
                cout<<mid<<endl;
                cin>>in;
                if(in =="<"){
                        r = mid - 1;
                }

                else{
                        l = mid;
                }

        }
        if(in == ">=")
        cout<<"! "<<mid<<endl;
        
        else{
                cout<<"! "<<mid-1<<endl;
        }
}

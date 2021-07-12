#include<bits/stdc++.h>
using namespace std;
set<int> gen;
int a,b,n;
void in(int aa){
        if(gen.size() >= n) return;
        gen.insert(aa);
        in(a*aa);
        in(aa + b);
}
int main(){
        cout<<"Enter the size \n";
        cin>>n;
        cout<<"Enter a and b\n";
        cin>>a>>b;
        gen.insert(1);
        in(1);
        for(auto t: gen) cout<<t<<" "; 
}

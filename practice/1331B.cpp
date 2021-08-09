#include<bits/stdc++.h>
using namespace std;
int main(){
int a;
cin>>a;
vector<int> v;
for(int i = 2; i  < a; i++){
if(a%i == 0) v.push_back(i);
}
cout<<v[0]<<a/v[0];
}

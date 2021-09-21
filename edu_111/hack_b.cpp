#include<bits/stdc++.h>
using namespace std;
void Solve(void){
  string s;
  short n,a,b,c=1;
  cin>>n>>a>>b>>s;
  for(short i=1;i<n;i++)
    if(s[i]!=s[i-1])c++;
  cout<<(a*n)+max(b*n,b*((c/2)+1))<<endl;
}
int main(void){
  short t;cin>>t;while(t--)
  Solve();
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int trac = 0;
        int i;
        for(i = 1; i < n; i++){
                if(s[i] == s[trac]){
                        trac++;
                }
                else if(s[i] > s[trac]) break;
                else trac = 0;
        }
        i -= trac;
        for(int j = 0; j < k; j++){
                cout<<s[j%i];
        }
}
//#include <bits/stdc++.h>
//#define f first
//#define s second
//#define mp make_pair
//#define pb push_back
//#define p push
//#define ins insert
//#define t top
//#define fr front
//#define H 500010
//#define MOD 1000000007
 
//using namespace std;
//typedef long long int LL;
//typedef pair<LL,LL> pii;
// 
//int N,K;
//char buf[H];
//int main() {
//    scanf("%d%d",&N,&K);
//    scanf("%s",&buf);
//    int l = 0;
//    int i;
//    for (i=1; i<N; i++) {
//        if (buf[i]==buf[l]) {
//            l++;
//        } else if (buf[i] > buf[l]) {
//            break;
//        } else {
//            l=0;
//        }
//    }
//    i-=l;
//    for (int j = 0; j < K; j++) {
//        cout << buf[j%i];
//    }
//    cout << endl;
//}

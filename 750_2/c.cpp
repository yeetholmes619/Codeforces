//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
#define curtime             chrono::high_resolution_clock::now()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
using namespace std;
#define RESET   "\033[0m"
#define BR   "\033[1m\033[31m"      /* Bold Red */
#define BG   "\033[1m\033[32m"      /* Bold Green */
#define BB    "\033[1m\033[34m"      /* Bold Blue */
#define ll long long
#define ld long double
#define INF 1000000007
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
/**
 * I/O
 **/
#define int long long
#define output(value) cout << value << endl
#define error(errorString) cout << BR << errorString << RESET<< "\n"
#define info(infoString) cout << BB << infoString << RESET << "\n"
#define success(successString) cout << BB << successString << RESET << "\n"
#define allarr(a,n) a, a+n
#define MOD 1000000007
// precedence order :- double > float > long long int > long int > int > char
// remember that boolean arrays and variables if uninitialized are given false
//Check if constraints are correct
// for single arrays declare them as long long int
//overflow must be taken care of!! use strings when big
//	0 < |int| < 1e9
//	0 < |long int| < 1e12
//	0 < |long long int| < 1e18
//when you are working with stacks, remember to take care of stacks of 0 size
//when you see a problem, and you know how you would tackle it in the real world, but don't know how
//you would do it in code, go step by step, in each step try to be concious of what you want to do
//and once you have done so, review through and remember what data structure would be perfect
//when we pass an array in a function the pointer is passed but when we pass a vector, a copy is passed
template<class T>
void debug(vector<T> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
template <class T>
void _print(vector<T> v){
        for(auto t: v) cout<<t<<" ";
        cout<<"\n";
}
template <class T>
void _print(T k){
        cout<<k<<"\n";
}
template <class T>
void _print2(vector<T> v){
        for(auto t: v) _print(t);
}
bool ispal(string s){
        int nn = s.size();
        for(int i = 0; i < nn; i++){
                if(s[i] != s[nn-1-i]) return false;
        }
        return true;
}
int n;
string s;
void take(){
        cin>>n;
        cin>>s;
}
void solve(){
        take();
        int ans = INT_MAX;
        if(ispal(s)){
                cout<<0<<"\n";
                return;
        }
        for(char i = 'a'; i <= 'z'; i = (char)(i+1)){
                string tt = "";
                vector<int> ind;
                //for(auto t: s) if(t != i) tt += t;
                for(int j = 0; j < n; j++){
                        if(s[j] != i){
                                tt += s[j];
                                ind.pb(j);
                        }
                }
                int cnt = 0;
                if(ispal(tt)){
                        int l = ind[(tt.size()-1)/2];
                        int r = ind[(tt.size())/2];
//                        cerr<<i<<" "<<l<<" "<<r<<"\n";
                        while((r < n) and (l > -1)){
 //                               cerr<<cnt<<" "<<l<<" "<<r<<"\n";
                                if(s[l] == s[r]){ r++;l--;}
                                else if(s[l] == i){ l--;cnt++;}
                                else{ r++;cnt++;}
                        }
                          cnt += max(l+1,0LL);
                        cnt += max(n-1-r+1,0LL);
                        ans = min(ans,cnt);
   //                     cerr<<ans<<" "<<i<<"\n";
                }
        }
        if(ans == INT_MAX){
                cout<<-1<<"\n";
        }
        else cout<<ans<<"\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

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
int n;
string s;
void take(){
        cin>>n;
        cin>>s;
}

void solve(){
        take();
        vector<int> isa(n+5,0);
        vector<int> isb(n+5,0);
        vector<int> isc(n+5,0);
        vector<int> cna(n+5,0);
        vector<int> cnb(n+5,0);
        vector<int> cnc(n+5,0);
        int codeforces_sucks = 68;
        codeforces_sucks++;
        for(int i =0 ; i < n; i++){
                if(s[i] == 'a'){
                        isa[i]++;
                }
                else if(s[i] == 'b'){
                        isb[i]++;
                }
                else isc[i]++;
        }
        cna[0] = isa[0];
        cnb[0] = isb[0];
        cnc[0] = isc[0];
        for(int i = 1; i <n; i++){
                cna[i] = cna[i-1] + isa[i];
                cnb[i] += cnb[i-1] + isb[i];
                cnc[i] += cnc[i-1] + isc[i];
        }
        int ans = INT_MAX;
        for(int sz = 2; sz <= min(n,10LL); sz++){
                for(int i = 0; i < n-sz+1; i++){
                       int a = cna[i+sz-1] - cna[i] + isa[i]; 
                       int b = cnb[i+sz-1] - cnb[i] + isb[i]; 
                       int c = cnc[i+sz-1] - cnc[i] + isc[i]; 
                       if((a > b) and (a > c)) {
                               cerr<<i<<" "<<sz<<"\n";
                               cerr<<a<<" "<<b<<" "<<c<<"\n";
                               ans = min(ans, sz);
                        }
                }
        }
        if(ans == INT_MAX) cout<<-1<<"\n";
        else cout<<ans<<"\n";
}


int32_t main() {
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

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
#define fu(i,n) for(int i = 0; i < n; i++)
#define fu1(i,n) for(int i = 1; i <= n; i++)
#define fd(i,n) for(int i = n-1; i > -1; i--)
#define fd1(i,n) for(int i = n ; i >= 1; i--)
#define vi vector<int>
#define vs vector<string>
#define pi pair<int,int>
#define umap unordered_map
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
/**
 * I/O
 **/
#define int long long
#define output(value) cout << value << "\n"
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
void take(vector<T> &v, int &n){
        cin>>n;
        v.resize(n);
        cinarr(v);
}
template<class T>
void take(vector<vector<T>> &v, int &n, int &m ){
        cin>>n>>m;
        v.resize(n,vector<T>(m));
        for(int i =0 ;i < n; i++){
                for(int j = 0; j < m; j++){
                        cin>>v[i][j];
                }
        }
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\DEBUG/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n"<<RESET;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr <<BR<< "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
int n,k,x;
string s;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
        cin>>n>>k>>x;
        cin>>s;
        debug(n,k,x);
        debug(s);
}

void solve(){
        take();
        x--;
        vector<int> bb;
        if(s[0] == '*') bb.pb(k);
        for(int i = 1; i < n; i++){
                if(s[i] == '*'){
                        if(s[i-1] != '*') bb.pb(k);
                        else bb[bb.size()-1] += k;
                }
        }
        debug(bb);
        if(bb.size() != 0 and k != 0){
                int bn = bb.size();
                vector<int> p(bn,1e18+9);
                p[bn-1] = 1;
                for(int i = bn-2; i > -1; i-- ){
                        if((1e18+982)/p[i+1] < bb[i+1]) break;
                        p[i] = p[i+1]*bb[i+1]+1;
                }
                debug(p);
                int ord = bn-1;
                for(;ord > -1; ord--){
                        if(x < p[ord]) break;
                }
                if(ord == bn-1) ord--;
                ord++;
                debug(ord);
                vector<int> ans;
                for(int i= ord; i < bn; i++){
                        debug(x,p[i]);
                        int tt = x/p[i];
                        ans.pb(tt);
                        x -= tt*p[i];
                }
                debug(ans);
                int ptr = ans.size()-1;
                string nn = "";
                nn += s[0];
                for(int i = 1; i < n; i++){
                        if(s[i] == '*'){
                                if(s[i-1] == '*') continue;
                                else nn += '*';
                        }
                        else nn += 'a';
                }
                s = nn;
                n = s.size();
                string fin = "";
                for(int i = n-1; i  > -1; i--){
                        if(s[i] == '*'){
                                if(ptr < 0) continue;
                                string tempt = string(ans[ptr],'b');
                                fin= tempt + fin;
                                ptr--;
                        }
                        else fin = 'a'  +fin;
                }
                cout<<fin<<"\n";
        }
        else{
                for(auto t: s) if(t != '*') cout<<t;
                cout<<"\n";
        }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 1 ; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

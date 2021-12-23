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
#define fup(i,a,b) for(int i = a; i <= b; i++)
#define fu1(i,n) for(int i = 1; i <= n; i++)
#define fd(i,n) for(int i = n-1; i > -1; i--)
#define fd1(i,n) for(int i = n ; i >= 1; i--)
#define fdo(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
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
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
 
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
	for (auto &it : v)
		cin >> it;
	return istream;
}
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
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
        cin>>n>>k>>x>>s;
        debug(n,k,x,s);
}
int find_pos(vi base, int num){
        int ns = (int)base.size();
        if(num <= base[ns-1]) return ns-1;
        int cache = 1;
        int ind = -1;
        fdo(i,ns-1,1){
                cache = cache*base[i] + cache-1;
                if(num/(cache+1) <= base[i-1]){
                        ind = i;
                        break;
                }
        }
        assert(ind != -1);
        return ind-1;
}
        

vi mixedbase(vi base, int num){
        vi ans;
       // if(!base.size()) return ans;
       // int ind =  find_pos(base,num);
       // vi precomp;
       // int ns = (int)base.size();
       // int cache = 1;
       // fdo(i,ns-1,ind){
       //         cache = cache*base[i] + cache-1;
       //         precomp.pb(cache);
       // }
       // reverse(allvec(precomp));
       // fup(i,ind,ns-2){
       //         ans.pb(num/(precomp[i-ind+1]+1));
       //         num -= (num/(precomp[i-ind+1]+1))*(precomp[i-ind+1]+1);
       // }
       // ans.pb(num);
       while(num){
               ans.pb(num%(base.back()+1));
               num /= (base.back()+1);
               base.pop_back();
       }
       reverse(allvec(ans));
        return ans;
}


void solve(){
        take();
        vi base;
        int c = 0;
        fup(i,0,n-1){
                if(s[i] == 'a'){
                        if(c!= 0) base.pb(c*k);
                        c = 0;
                }
                else{
                        c++;
                }
        }
        if(c != 0)base.pb(c*k);
        debug(base);
        string ss = "";
        fup(i,0,n-1){
                if(s[i] == '*'){
                        if((ss.size() == 0 or ss.back() == 'a') and (k!=0)) ss += '*';
                }
                else ss += 'a';
        }
        debug(ss);
        vi fin = mixedbase(base,x-1);
        debug(fin);
        int st =(int)fin.size() -1 ;
        n = ss.size();
        string ans = "";
        fdo(i,n-1,0){
                if(ss[i] == '*'){
                        if(st < 0) continue;
                        ans += string(fin[st],'b');
                        st--;
                }
                else ans += ss[i];
        }
        reverse(allvec(ans));
        debug(ans);
        cout<<ans<<"\n";

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

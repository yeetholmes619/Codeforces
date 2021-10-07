//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define BR   "\033[1m\033[31m"      /* Bold Red */
#define BG   "\033[1m\033[32m"      /* Bold Green */
#define BB    "\033[1m\033[34m"      /* Bold Blue */
#define ll long long
#define ld long double
#define INF 1000000007
#define fu(i,a,b) for(ll i = a; i<=b;i++)
#define fd(i,a,b) for(ll i = a; i>=b; i--)
#define fdd(i,a) for(ll i = a; i>=1; i--)
#define fuu(i,a)for(ll i = 1; i<=a; i++)
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
#define vstr vector<string>
#define vll vector<ll>
#define vint vector<int>
/**
 * I/O
 **/
using namespace std;
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
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
int n,m,d;
vector<string> in;
void take(){
        cin>>n>>m>>d;
        in.resize(n);
        cinarr(in);
        in.insert(in.begin(),string(m+2,'.')); 
        in.pb(string(m+2,'.'));
        for(int i = 1; i <= n; i++){
                in[i] += '.';
                in[i] = '.' + in[i];
        }
        //debug(in);
}
void demark(vector<pair<int,int>> &p , int x, int y){
        int i = x, j1 = y, j2 = y;
        while(in[i][j1] == '*' and in[i][j2] == '*'){
                p.pb({i,j1});
                p.pb({i,j2});
                i--;
                j1--;
                j2++;
        }
}
void draw(vector<pair<int,int>> &p, vector<string> &c){
        for(auto t: p){
                c[t.first][t.second] = '*';
        }
}
void solve(){
        take();
        vector<string> check(n+2,string(m+2,'.'));
        for(int i = 1; i < n+1; i++){
                for(int j = 1; j < m+1; j++){
                        if(in[i][j] == '*'){
                                vector<pair<int,int>> p;
                                demark(p,i,j);
                                if(p.size() >= 2*d + 2){
                                        draw(p,check);
                                }
                        }
                }
        }
        //debug(check);
        //debug(in);
        if(check == in){
                cout<<"YES\n";
        }
        else cout<<"NO\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

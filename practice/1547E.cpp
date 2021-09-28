//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define BR   "\033[1m\033[31m"      /* Bold Red */
#define BG   "\033[1m\033[32m"      /* Bold Green */
#define BB    "\033[1m\033[34m"      /* Bold Blue */
#define ll long long
#define ld long double
#define INF 10000000007
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
void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
int n, k;
vector<int> v;
map<int,int> temp;

void take(){
        v.clear();
        temp.clear();
        cin>>n>>k;
        v.resize(k);
        for(int i =0 ; i < k; i++){
                cin>>v[i];
                v[i]--;
        }
        for(int i = 0; i < k; i++) cin>>temp[v[i]];
}

void solve(){
        take();
        sort(allvec(v));
        vector<int> ans(n,0);
        vector<int> minl(n,INF);
        vector<int> minr(n,INF);
        for(int i =0 ; i < k; i++){
                minl[v[i]] = temp[v[i]] - v[i]; 
                minr[v[i]] = temp[v[i]] + v[i]; 
        }
        for(int i = 1; i  < n; i++){
                minl[i] = min(minl[i],minl[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
                minr[i] = min(minr[i],minr[i+1]);
        }
        for(int i = 0; i < n; i++){
                ans[i] = min(minl[i] + i, minr[i] - i);
                cout<<ans[i]<<" ";
        }
        cout<<"\n";

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

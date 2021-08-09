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
void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
int n;
vector<int> a;
vector<int> b;
void take(){
        cin>>n;
        a.clear();
        b.clear();
        a.resize(n+1);
        b.resize(n+1);
        b[0] = 1e10;
        a[0] = 1e10;
        for(int i = 1; i <n+1; i++){
                cin>>a[i];
        }
        for(int i = 1; i <n+1; i++){
                cin>>b[i];
        }
}
int sz(int l){
        return l - (l/4);
}
void solve(){
        take();
        int mx = 2e5+5;
        sort(allvec(a),greater<int>());
        sort(allvec(b),greater<int>());
        vector<int> besta(n+1);
        vector<int> bestb(n+1);
        besta[1] = a[1];
        bestb[1] = b[1];
        int cnta = 0, cntb = 0;
        for(int i = 1; i <= sz(n); i++){
                cnta += a[i];
                cntb += b[i];
        }
        if(cnta >= cntb){
                cout<<0<<"\n";
                return;
        }
        for(int i = 2; i < n+1; i++){
                besta[i] = besta[i-1] + a[i];
                bestb[i] = bestb[i-1] + b[i];
        }

        int l = 0, r = mx, mid,ans = -1;

        while(l <= r){
                mid = (l+r)/2;
                int k = sz(n + mid);
                int rem = max(0LL,k - mid);
                int sca = 100*mid + besta[rem], scb = bestb[min(n,k)];
                assert(k-mid <= n);
                if(sca >= scb){
                        ans = mid;
                        r = mid-1;
                }
                else{
                        l = mid + 1;
                }
        }
        cout<<ans<<"\n";


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

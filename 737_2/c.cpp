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
#define int long long
#define fu(i,a,b) for(ll i = a; i<=b;i++)
#define fd(i,a,b) for(ll i = a; i>=b; i--)
#define fdd(i,a) for(ll i = a; i>=1; i--)
#define fuu(i,a)for(ll i = 1; i<=a; i++)
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
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
#define error(errorString) cout << BR << errorString << RESET
#define info(infoString) cout << CYAN << infoString << RESET << endl
#define success(successString) cout << GREEN << successString << RESET << endl
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

long long power_mod(long long a, long long b){
        long long m = MOD;
        if(b == 0) return 1LL;
        if(b == 1) return (a%m);
        long long ans = 1;
        while(b > 0){
                if(b%2 == 1) ans = (ans*a)%m;
                a = (a*a)%m;
                b /=2;
        }
        return ans;
}
int n,k;
void take() {
        cin>>n>>k;
}
void solve() {
        take();
        if(n == 1){
                cout<<power_mod(2,k)<<"\n";
                return;
        }
        if(k == 0){
                cout<<1<<"\n";
                return;
        }
        if(n%2 == 0){
                long long w = power_mod(2LL,n-1);
                cout<<(k*w)%MOD<<"\n";
        }
        else{
                long long ans = 0;
                long long temp = power_mod(2LL,n-1);
                int w = temp + 1;
                int l = temp - 1;
                for(int i = 0; i < k; i++){
                        ans %= MOD;
                        int gg = power_mod(w,k-i)*power_mod(l,i);
                        gg %= MOD;
                        ans += gg;
                        ans %= MOD;
                }
                cout<<ans%MOD<<"\n";
        }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		solve();
	}
}

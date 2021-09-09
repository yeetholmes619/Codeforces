//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define BR   "\033[1m\033[31m"      /* Bold Red */
#define BG   "\033[1m\033[32m"      /* Bold Green */
#define BB    "\033[1m\033[34m"      /* Bold Blue */
#define ll long long
#define ld long double
#define int long long
#define INF 1000000007
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
    /**
// if n is odd:
    in order to draw we need even number of 1s.
    nC0 + nC2 + nC4 + nC6 + ....
     = (2^(n-1) +1)^k;

    in order to win, we need all ones, so only one way
    = 0;
// if n is even:
    in order to draw we still need even number of 1s
    2^(n-1)-1;

    in order to win there is still only one way
    = 1;

    **/
 


void take() {
        cin>>n>>k;
}
void solve() {
        take();
        if(k == 0){
                cout<<1<<"\n";
                return;
        }
        int d,ans = 0;
        if(n%2 == 0) d = (power_mod(2LL,n-1)-1)%MOD;
        else{
                cout<<power_mod((power_mod(2LL,n-1) + 1),k)<<"\n";
                return;
        }
        for(int i = 0; i < k+1; i++){
                ans += ((power_mod(d,i)%MOD)*(power_mod(power_mod(2LL,n)%MOD,max(k-i-1,0LL))%MOD))%MOD;
                ans %= MOD;
        }
        ans %= MOD;
        cout<<ans<<"\n";
                

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

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
#define MOD 1
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
const int m = 998244353; 
int fact[1000000];
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y);

// Function to find modulo inverse of a
int modInverse(int a)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) assert(false);
    else
    {

        // m is added to handle negative x
        int res = (x % m + m) % m;
        return res;
    }
}

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int ncr(int nn, int rr){
        if(nn < rr) return 0;
        if(rr == 0) return 1;
        //return (fact[nn]*modInverse(fact[rr])%m*modInverse(fact[nn-rr])%m)%m;
        int res = fact[nn];
        res *= modInverse(fact[rr]);
        assert(res >=0);
        res %= m;
        assert(res >=0);
        res *= modInverse(fact[nn-rr]);
        assert(res >=0);
        res %= m;
        assert(res >=0);
    //    int n = fact[nn];
    //    int d = fact[nn-rr]*fact[rr];
    //    int res = n/d;
    //    res %= m;
        return res;
}
int n;
vector<int> jury;
void take() {
        cin>>n;
        jury.clear();
        jury.resize(n);
        cinarr(jury);
        sort(allvec(jury));
}
void solve() {
        take();
        int a = jury[n-1];
        int b = jury[n-2];
        if(a - b > 1){
                cout<<0<<"\n";
                return;
        }
        if(count(allvec(jury),a) > 1){
                cout<<fact[n]<<"\n";
                return;
        }
        int k = count(allvec(jury),b);
        int sum = 0;
        int j = n-k-1;
        for(int i = 0; i <= n-k-1; i++){
                int res = ncr(n-k-1,i);
                res *= fact[i];
                res %= m;
                res *= fact[n-i-1];
                res %= m;
                sum += res;
                sum %= m;
        }
        int ans = (fact[n]+ m - sum)%m;
        //assert(ans >= 0);
        ans %= m;
        cout<<ans<<"\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < 500000; i++){
            fact[i] = (i*fact[i-1])%m;
            fact[i] %= m;
    }
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

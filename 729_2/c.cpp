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
int prime[100000];	// prime number hash map
					// prime[i] = 1 means i is prime
					// prime[i] = 0 means i is not prime

int primeList[10000];	// array containing only prime numbers
int pl_len;				// length of primelist
void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
void SieveOfEratosthenes(int n = 100000) {

	int p, j;

	// set all elements of prime[] to 1
	for (j = 0; j < n; ++j)
		prime[j] = 1;

	prime[1] = 0; // 1 is not prime
	for (p = 2; p <= sqrt(n); ++p) {
		for (j = p * p; j < n; j += p) {
			prime[j] = 0;
		}
	}

	// creating list of prime numbers
	pl_len = 0;
	for (p = 2; p < n; ++p) {
		if (prime[p] == 1)
			primeList[pl_len++] = p;
	}

}

int f(int n) {
        int cache = 2;
        if(n%2 == 1) return 2;
        if(n==2) return 3;
        for(int i = 1; primeList[i] < n; i++){
                if(n%primeList[i] == 0){
                        if(n%primeList[i-1] == 0){
                                cache = primeList[i];
                        }
                        else break;
                }
                else break;
        }
        for(int j = cache+1;;j++){
                if(n%j != 0) return j;
        }
        return -1;
}

vector<int> nums;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfEratosthenes();
	ll t = 1;
	cin >> t;
    //nums.resize(t);
    int n;
    cerr<<BB<<f(1)<<RESET<<"\n";
	fuu(i, t) {
            cin>>n;
            error(n);
            cerr<<"\n";
            nums.pb(n);
	}
    vector<int> v(t);
    for(int i = 0; i < t; i++){
            v[i] = nums[i];
    }
    sort(allvec(v));
    vector<int> ans(t,0);
    int sum = 0;
    for(int i = 1; i <=  v[0]; i++){
            sum += f(i)%MOD;
            sum %= MOD;
    }
    ans[0] = sum;
    int start = 1;
    for(int i = 1; i < t; i++){
            for(int j = v[i-1] + 1; j <= v[i]; j++){
                    ans[i] += f(j)%MOD;
                    ans[i] %= MOD;
            }
            ans[i] += ans[i-1];
            ans[i] %= MOD;
    }
    for(int i = 0; i < t; i++){
            cout<<v[i]<<" "<<ans[i]<<"\n";
    }              
}

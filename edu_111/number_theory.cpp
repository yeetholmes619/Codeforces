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
vector<bool> sieve(long long n){
        vector<bool> prime(n+1,true);
        prime[0] = prime[1] = false;
        for(long long i = 2; i*i <= n; i++){
                if(prime[i]){
                        for(long long j = i*i; j <=n ; j += i){
                                prime[j] = false;
                        }
                }
        }
        return prime;
}

long long times(long long a, long long b){
        long long count = 0;
        while(b%a == 0){
                b/=a;
                count++;
        }
        return count;

}

long long eulerTotient(long long n){
        vector<bool> prime = sieve(n);
        long long num = 1;
        //long long den = 1;
        long long ans = 1;
        for(int i = 2; i < prime.size(); i++){
                if(n%i == 0 && prime[i]){
                        long long nulm = time(i,n);
                        num *= pow(i ,nulm-1);
                        num *= i-1;
                        //den *= pow(i,nulm);
                }
        }
        ans *= num;
        //ans /= den;
        return ans;
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

long long power_mod(long long a, long long b,long long m){
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
ll modInverse(ll a, ll m){
    for (ll x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}
//Miller Rabin start
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod = MOD) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

bool MillerRabin_accurate(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
//Miller Rabin End
vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

long long gcd_extended(long long a, long long b, long long &x, long long &y) {
    x = 1, y = 0;
    long long x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        long long q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

long long gcd(long long a, long long b){
        if(!b) return a;
        while(1){
                long long temp = b;
                b = a%b;
                a = temp;
                if(b == 0) break;
        }
        return a;
}


double log(double a, int b){return log(a)/log(b);}

long long mid(long long a, long long b) {return (a+b)/2;}

ll checkdigits(ll num) {
	ll digits = 0;
	while (num != 0) {
		num /= 10;
		digits += 1;
	}
	return digits;
}

string toBinary(ll n)
{
	string r;
	while (n != 0) {
		r = ( n % 2 == 0 ? "0" : "1" ) + r;
		n /= 2;
	}
	return r;
}
void take() {
}
void solve() {
        take();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		cout << "Case #" << i << ": ";
		solve();
	}
}

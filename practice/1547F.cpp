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
#define MAXN   10000000

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
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

set<int> factors(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
//        set<int> factors(int a){
//                set<int> ans;
//                if(a == 1) return ans;
//                if(a%2 == 0){
//                        ans.insert(2);
//                        while(a%2 == 0) a/=2;
//                }
//                for(int i = 3; i <= (int)(sqrt(a)); i++){
//                        if(a%i == 0){
//                                ans.insert(i);
//                                while(a%i == 0) a/=i;
//                        }
//                }
//                if(a != 1) ans.insert(a);
//                assert(a != 0);
//                return ans;
//        }

int n;
vector<int> v;
void take() {
        cin>>n;
        v.clear();
        v.resize(n);
        cinarr(v);
}
void solve() {
        take();
        vector<set<int>> fact(n);
        int common = v[0];
        int answer= 0;
        for(int i =0 ; i < n; i++){
                common = gcd(common,v[i]);
        }
        for(int i =0 ; i  <n; i++) v[i] /= common;
        for(int i =0 ; i < n; i++) fact[i] = factors(v[i]);

        for(int i = 0; i < n; i++){
                for(auto p: fact[i]){
                        int l = i;
                        int r = (i+1)%n;
                        int cnt= 0;
                        while(fact[l].count(p) > 0){
                                if(l != i){
                                        fact[l].erase(p);
                                }
                                l--; cnt++;
                                l = (l + n)%n;
                        }
                        while(fact[r].count(p) > 0){
                                fact[r].erase(p);
                                r++; r%=n; cnt++;
                        }
                        answer = max(answer,cnt);
                }
                fact[i].clear();
        }
        cout<<answer<<"\n";

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

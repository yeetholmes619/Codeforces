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
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
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
vector<bool> isprime;
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
void debug(vector<int> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
string in,n;
void take(){
        cin>>in;
        n = in.size();
}
vector<int> see;
void check(string s,int index,int left){
        if((index >= n-1) and(left != 0)) return;
        if(left == 0){
                int i = stoll(s);
                see.pb(i);
        }
        bool ans = false;
        for(int i = index+1; i<n; i++){
                string temp = s += in[i];
                check(temp,i,left-1);
        }
}
void solve(){
        take();
        check("",-1,1);
        for(auto t: see){
                if(!isprime[t]){
                        cout<<1<<"\n";
                        cout<<t<<"\n";
                        return;
                }
        }
        see.clear();
        check("",-1,2);
        for(auto t: see){
                if(!isprime[t]){
                        cout<<2<<"\n";
                        cout<<t<<"\n";
                        return;
                }
        }
        see.clear();
        check("",-1,3);
        for(auto t: see){
                if(!isprime[t]){
                        cout<<3<<"\n";
                        cout<<t<<"\n";
                        return;
                }
        }
        see.clear();
        check("",-1,4);
        for(auto t: see){
                if(!isprime[t]){
                        cout<<4<<"\n";
                        cout<<t<<"\n";
                        return;
                }
        }
        see.clear();
        check("",-1,5);
        for(auto t: see){
                if(!isprime[t]){
                        cout<<5<<"\n";
                        cout<<t<<"\n";
                        return;
                }
        }
        see.clear();
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    isprime = sieve(100000);
	ll t = 1;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

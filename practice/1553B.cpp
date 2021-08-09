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
string a,b;
int n,m;
int dp[600][600];
bool poss(int index, int length,bool cangoright){
        if(length == m) return true;
        if(index < 0 or index == n) return false;
        if(dp[index][length] != -1) return dp[index][length];
        if(a[index] == b[length]){
                if(cangoright){
                        dp[index][length] = max(poss(index-1,length+1,0),poss(index+1,length+1,1));
                        return dp[index][length];
                }
                dp[index][length] = poss(index-1,length+1,0);
                return dp[index][length];
        }
        return false;
}
void take(){
        memset(dp,-1,sizeof(dp));
        cin>>a;
        cin>>b;
        n = a.size();
        m = b.size();
}
void solve(){
        take();
        int ans = 0;
        for(int i = 0 ; i < n; i++){
                if(a[i] == b[0])
                ans = max(ans,(ll)poss(i,0,1));
        }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
    //argon17();
	}
}

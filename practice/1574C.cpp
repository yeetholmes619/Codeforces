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
int n,m;
vector<int> h;
vector<pair<int,int>> d;
void take(){
        cin>>n;
        h.resize(n);
        cinarr(h);
        cin>>m;
        d.resize(m);
        for(int i = 0; i < m; i++){
                cin>>d[i].first>>d[i].second;
        }
}

void solve(){
        take();
        sort(allvec(h));
        int sum = 0;
        for(auto t: h) sum += t;
        for(int i =0 ; i < m ; i++){
                int g = 0;
                int it = lower_bound(allvec(h),d[i].first) - h.begin();
                error(it);
                if((it == 0) or (it == n)){
                        if(it == 0){
                                g += d[i].second-sum+h[0];
                                g = max(g,0LL);
                                cout<<max(g,0LL)<<"\n";
                        }
                        else{
                                g += d[i].second-sum+h[n-1];
                                g = max(g,0LL);
                                g += d[i].first - h[n-1];
                                g = max(g,0LL);
                                cout<<max(g,0LL)<<"\n";
                        }
                }
                else{
                        int c1 = 0;
                        int c2 = 0;
                        c1 += h[it] - d[i].first;
                        c1 = max(0LL,c1);
                        c2 +=  d[i].first- h[it-1];
                        c2 = max(0LL,c2);
                        c1 += max(-1*(sum - h[it]- d[i].second),0LL);
                        c1 += max(-1*(sum - h[it-1]- d[i].second),0LL);
                        cout<<min(c1,c2)<<"\n";
                }
        }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

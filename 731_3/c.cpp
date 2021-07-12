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
//#define int long long
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
void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
int k,n,m;
void take(){
        cin>>k>>n>>m;
       // cerr<<BR<<k<<" "<< n<<" "<<m<<"\n"<<RESET;
}

void solve(){
        take();
        int a[n],b[m];
        cinarr(a);
        cinarr(b);
        int sa = 0, sb = 0;
        int l = k;
        vector<int> steps;
        while((sa != n) or (sb != m)){

                if(sa < n)
                if(a[sa] == 0){
                        steps.pb(0);
                        sa++;
                        l++;
                        continue;
                }

                if(sb < m)
                if(b[sb] == 0){
                        steps.pb(0);
                        sb++;
                        l++;
                        continue;
                }

                if(sa < n)
                if(a[sa] <= l){
                        steps.pb(a[sa]);
                        sa++;
                        continue;
                }

                if(sb < m)
                if(b[sb] <= l){
                        steps.pb(b[sb]);
                        sb++;
                        continue;
                }
                cout<<-1<<"\n";
                return;
        }
        //cerr<<BB<<sa<<" "<<sb<<"\n"<<RESET; 
        for(auto &t : steps) cout<<t<<" ";
        cout<<"\n";
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

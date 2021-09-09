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
void debug(vector<int> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
int n;
vector<int> v;
void take(){
        cin>>n;
        v.clear();
        v.resize(n);
        cinarr(v);
}

void solve(){
        take();
        if(n == 1){
                cout<<0<<"\n";
                return;
        }
        vector<int> z;
        for(int  i =1 ; i <= n; i++){
                if(v[i-1]%2 == 0) z.pb(i);
        }
        int co = n - z.size();
        int cz = z.size();
        if(abs(co - cz) > 1){
                cout<<-1<<"\n";
                return;
        }
        else{
                        int ans1 = 0, ans2 = 0;
                        int k = 2;
                        int kk = 1;
                        for(int i = 0; i < cz; i++){
                                ans1 += abs(z[i] - k);
                                ans2 += abs(z[i] - kk);
                                k += 2;
                                kk += 2;
                        }
                        if(cz == co){
                                cout<<min(ans1,ans2)<<"\n";
                        }
                        else if(cz > co){
                                cout<<ans2<<"\n";
                        }
                        else{
                                cout<<ans1<<"\n";
                        }
        }

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

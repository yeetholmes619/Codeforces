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
        for(auto t: v) cerr<<BR<<t<<"\n"<<RESET;
        cerr<<"\n";
}
int n;
void take(){
        cin>> n;
}

void solve(){
        take();
        string s = to_string(n);
        int sol = 1e10;
        for(int i = 0; i < 65; i++){
                int p = 1LL<<i;
                string pp = to_string(p);
                int pn = pp.size();
                int sn = s.size();
                int it1 = 0;
                int it2 = 0;
                int ans = 0;
                while((it2 < pp.size()) and (it1 < s.size())){
                        if(s[it1] == pp[it2]){
                                it1++;
                                it2++;
                        }
                        else{
                                ans++;
                                it1++;
                        }
                }
                if(it1 == sn and it2 == pn){
                        sol = min(ans,sol);
                }
                else if(it1 == s.size()){
                        sol =min(sol,ans+ pn- it2 );
                }
                else{
                        sol = min(sol,ans + sn-it1);
                }
        }
        cout<<sol<<"\n";
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

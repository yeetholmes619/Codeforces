//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
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
vector<int> vo;
vector<int> ve;
map<int,int> m;
void take(){
        cin>>n;
        vo.clear();
        ve.clear();
        vo.resize(n);
        ve.resize(n);
        cinarr(vo);
        cinarr(ve);
        m.clear();
}

void solve(){
        take();
        if(n == 1){
                cout<<0<<"\n";
                return;
        }
        for(int i = 0; i < n; i++){
                m[vo[i]] = i;
                m2[ve[i]] = i;
        }
        vector<int> ans(2*n+5);
        ans[1] = m[1];
        for(int i = 2; i <= 2*n; i++){
                if(i%2 == 0) ans[i] = ans[i-1];
                else ans[i] = min(ans[i-1],m[i]);
        }
        int a = MOD;
        for(int i = 0; i < n; i++){
                a = min(a,i+ans[ve[i]]);
        }
        cout<<a<<"\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

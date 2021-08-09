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
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
int n,k;
vector<int> v;
void take(){
        v.clear();
        cin>>n>>k;
        v.resize(n);
        cinarr(v);
}

void solve(){
        take();
        vector<pair<int,int>> vv;
        for(int i = 0; i < n; i++){
                vv.pb(make_pair(v[i],i));
        }
        sort(allvec(vv));
        vv.pb(make_pair(-1,n));
        vector<int> non_repeating;
        vector<pair<int,int>> repeating;
        int start = 0;
        int end = 0;
        while(start < n){
                int times =  1;
                while(vv[start].first == vv[end].first) end++;
                times = end-start;
                if(times ==  1) non_repeating.pb(start);
                else repeating.pb(make_pair(times,start));
                start = end;
        }

       // for(auto t: non_repeating){
       //         cerr<<BR<<vv[t].first<<" "<<RESET;
       // }
       // cerr<<"\n";

        //for(auto t: repeating){
       //         cerr<<BB<<t.first<<" "<<vv[t.second].first<<" "<<RESET;
       // }
       // cerr<<"\n";

        vector<int> ans(n,0);

        vector<int> cache;
        
        while(non_repeating.size()%k != 0){
                int tt = non_repeating.size()-1;
                cache.pb(non_repeating[tt]);
                non_repeating.pop_back();
        }

        //debug(cache);

        for(int i = 0; i < non_repeating.size() - (non_repeating.size()%k); i++){
                ans[vv[non_repeating[i]].second] = i%k + 1;
        }

        //debug(ans);

        for(int i = 0; i < repeating.size(); i++){
                if(repeating[i].first < k){
                        for(int l = 0; l < repeating[i].first; l++) cache.pb(repeating[i].second + l);
                }
                if(k!=1){
                        if(repeating[i].first >= k)
                                for(int j = 0; j < k; j++){
                                        ans[vv[repeating[i].second + j].second] = j%k + 1;
                                }
                }
                else ans[vv[repeating[i].second].second] = 1;
        }

        for(int i = 0; i < cache.size() - (cache.size()%k); i++){
                ans[vv[cache[i]].second] = i%k + 1;
        }

       // debug(ans);

        for(int i = 0; i < n; i++){
                cout<<ans[i]<<" ";
        }
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

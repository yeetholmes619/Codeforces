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
string s1,s2;
void take(){
        cin>>n;
        cin>>s1;
        cin>>s2;
}

void solve(){
        take();
        vector<pair<char,char>> v;
        v.resize(1);
        v[0] = mp(s1[0],s2[0]);
        for(int  i = 1; i < n; i++){
                if((s1[i] == '1') and (s2[i] == '1')){
                        if((v[v.size()-1].first == '0') and (v[v.size()-1].second == '0')){
                                v.pop_back();
                                v.pb(mp('1','0'));
                        }
                        else v.pb(mp('1','1'));
                }
                else if((s1[i] == '0') and (s2[i] == '0')){
                        if(v[v.size()-1] == mp('1','1')){
                                v.pop_back();
                                v.pb(mp('1','0'));
                        }
                        else v.pb(mp('0','0'));
                }
                else {
                        v.pb(mp(s1[i],s2[i]));
                }
        }

        int ans = 0;
        n = v.size();
        for(int i = 0; i < n; i++){
                if((v[i] == mp('1','0')) or (v[i] == mp('0','1'))){
      //                  cerr<<1;
                        ans += 2;
                }
                else if(v[i] == mp('0','0')){
                    ans++;
                }
        }
//        cerr<<"\n";
        cout<<ans<<"\n";
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

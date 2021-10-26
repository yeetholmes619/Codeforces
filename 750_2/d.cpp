//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
#define curtime             chrono::high_resolution_clock::now()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
//        std::random_device rd; // obtain a random number from hardware
//        std::mt19937 gen(rd()); // seed the generator
//        std::uniform_int_distribution<> distr(-5, 5); // define the range
template<class T>
void debug(vector<T> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
template <class T>
void _print(vector<T> v){
        for(auto t: v) cout<<t<<" ";
        cout<<"\n";
}
template <class T>
void _print(T k){
        cout<<k<<"\n";
}
template <class T>
void _print2(vector<T> v){
        for(auto t: v) _print(t);
}
int rand(int a, int b){
        return a + rand()%(b-a+1);
}
int n;
vector<int> v;
void take(){
        cin>>n;
        v.resize(n);
        cinarr(v);
}

void solve(){
        take();
        vector<int> ans(n,-1);
        set<int> s;
        for(auto t: v) s.insert(t);
        if(s.size() == 1){
                ans.resize(n,1);
                for(int i = 0; i < n-1; i++) cout<<1<<" ";
                cout<<-1*(n-1)<<"\n";
                return;
        }
        if(n%2 == 0){
                for(int i = 0; i < n; i += 2){
                        ans[i] = v[i+1];
                        ans[i+1] = -1*v[i];
                }
                _print(ans);
        }
        else{
                ans[0] = v[1]+v[2];
                ans[1] = -1*v[0];
                ans[2] = -1*v[0];
                for(int i = 3; i < n; i += 2){
                        ans[i] = v[i+1];
                        ans[i+1] = -1*v[i];
                }
                _print(ans);
        }
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

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
int n,p;
vector<int> l;
vector<int> r;
void take(){
        cin>>n>>p;
        l.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
                cin>>l[i]>>r[i];
        }
}

void solve(){
        take();
        vector<double> pp(n,0);
        for(int i = 2; i< n-1; i++){
                double a = r[i+1]/p - (l[i+1]+p-1)/p + 1;
                double b = r[i]/p - (l[i]+p-1)/p + 1;
                double c = r[i-1]/p - (l[i-1]+p-1)/p + 1;
                pp[i] += ((b/(r[i]-l[i]+1)) * (1.0/(r[i+1]-l[i+1]+1))) + ((1.0/(r[i]-l[i]+1)) * (a/(r[i+1]-l[i+1]+1)));
                pp[i] += ((b/(r[i]-l[i]+1)) * (1.0/(r[i-1]-l[i-1]+1))) + ((1.0/(r[i]-l[i]+1)) * (c/(r[i-1]-l[i-1]+1)));
        }
                double a = r[1]/p - (l[1]+p-1)/p + 1;
                double b = r[0]/p - (l[0]+p-1)/p + 1;
                double c = r[n-1]/p - (l[n-1]+p-1)/p + 1;
                pp[0] += ((b/(r[0]-l[0]+1)) * (1.0/(r[1]-l[1]+1))) + ((1.0/(r[0]-l[0]+1)) * (a/(r[1]-l[1]+1)));
                pp[0] += ((b/(r[0]-l[0]+1)) * (1.0/(r[n-1]-l[n-1]+1))) + ((1.0/(r[0]-l[0]+1)) * (c/(r[n-1]-l[n-1]+1)));
                 a = r[n-2]/p - (l[n-2]+p-1)/p + 1;
                 b = r[n-1]/p - (l[n-1]+p-1)/p + 1;
                 c = r[0]/p - (l[0]+p-1)/p + 1;
                pp[n-1] += ((b/(r[n-1]-l[n-1]+1)) * (1.0/(r[0]-l[0]+1))) + ((1.0/(r[n-1]-l[n-1]+1)) * (a/(r[0]-l[0]+1)));
                pp[n-1] += ((b/(r[n-1]-l[n-1]+1)) * (1.0/(r[n-2]-l[n-2]+1))) + ((1.0/(r[n-1]-l[n-1]+1)) * (c/(r[n-2]-l[n-2]+1)));
        double ans = 0;
        for(auto t: pp) ans += 1000*t;
        cout<<ans<<"\n";

}


int32_t main() {
        cout<<setprecision(8)<<fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

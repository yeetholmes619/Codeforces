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
string s;
void take(){
        cin>>s;
}

void solve(){
        take();

        string s1 = "",s2 = "";

        for(int i =0; i < 10; i++){
                if(s[i] == '?'){
                        if(i%2 == 0){
                                s1.pb('1');
                                s2.pb('0');
                        }
                        else{
                                s2.pb('1');
                                s1.pb('0');
                        }
                }
                else{
                        s1.pb(s[i]);
                        s2.pb(s[i]);
                }
        }
        //error(s1);
        //error(s2);

        int ans = 0,a = 0, b = 0, ka = 5,kb = 5;
        for(int i = 0; i < 10; i++){
                //cerr<<BG<<a<<" "<<b<<" "<<ka<<" "<<kb<<"\n"<<RESET;
                if(i%2 == 0) ka--;
                else kb--;
                if(s1[i] == '1'){
                        if(i%2 == 0) {
                                a++;
                        }
                        else {
                                b++;
                        }
                }

                if(a > b + kb){
                        ans = i + 1;
                        break;
                }
        }
        if(ans == 0) ans = 10;
        //error(ans);
        a = 0, b = 0, ka = 5,kb = 5;
        for(int i = 0; i < 10; i++){
               // cerr<<BG<<a<<" "<<b<<" "<<ka<<" "<<kb<<"\n"<<RESET;
                if(i%2 == 0) ka--;
                else kb--;
                if(s2[i] == '1'){
                        if(i%2 == 0) {
                                a++;
                        }
                        else {
                                b++;
                        }
                }

                if(b > a + ka){
                        ans = min(ans,i + 1);
                        break;
                }
        }
       // error(ans);

        if(ans == 0) ans = 10;
        cout<<ans<<"\n";

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

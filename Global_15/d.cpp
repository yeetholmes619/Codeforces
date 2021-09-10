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
int n;
void take(){
        cin>>n;
}
int myPow(int x, int p)
{
  if (p == 0LL) return 1LL;
  if (p == 1LL) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}
string decToBinary(int nn)
{
    // array to store binary number
    int binaryNum[n];
    for(int i = 0; i < n; i++){
            binaryNum[i] = 0;
    }
 
    // counter for binary array
    int i = 0;
    while (nn > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = nn % 2;
        nn = nn / 2;
        i++;
    }
 
    // printing binary array in reverse order
    string ans = "";
    for (int j = n-1; j >= 0; j--){
                ostringstream str1;
                str1 <<binaryNum[j];
            ans += str1.str();
    }
    return ans;
}

bool sum_search(vector<int> v, int take){
    
        for(int i = 1; i <= (myPow(2LL,n) - 1); i++){
                string s = decToBinary(i);
                //cerr<<BB<<i<<" "<<RESET;
                //cerr<<BR<<s<<" "<<RESET;
                int add = 0;
                int cc = 0;
                int majik = 0;
                for(int j = 0; j < n; j++){
                        if(s[j] == '1'){
                                cc++;
                                majik = j;
                                add += v[j];
                        }
                }
                if(cc == 1){
                        continue;
                }
                //cerr<<BG<<add<<"\n"<<RESET;
                if(abs(add) == abs(take)) return true;
        }

        return false;
}

void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}

void solve(){
        take();
        vector<int> a(n);
        cinarr(a);
        if(n == 1){
                if(a[0] == 0){
                        cout<<"YES\n";
                        return;
                }
                else{
                        cout<<"NO\n";
                        return;
                }
        }

        sort(allvec(a));
        for(int i = 1; i < n; i++){
                if(a[i] == a[i-1]){
                        cout<<"YES\n";
                        return;
                }
                if(a[i] == 0){
                        cout<<"YES\n";
                        return;
                }
        }
        if(n == 2){
                if((a[0] == 0) or (a[1] == 0)){
                         cout<<"YES\n"; 
                         return;
                }
               else if(a[0] == a[1]){
                        cout<<"YES\n";
                        return;
               }
                else{
                        cout<<"NO\n";
                        return;
                }
        }

        for(int i = 0; i < n; i++){
                vector<int> dummy;
                int cnt = 0;
                for(int j = 0; j < n; j++){
                        if(j == i){
                                cnt++;
                                if(cnt == 1) continue;
                        }
                        dummy.pb(a[j]);
                }
                if(sum_search(a,a[i])){
                        cout<<"YES\n";
                        return;
                }
        }
        cout<<"NO\n";
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
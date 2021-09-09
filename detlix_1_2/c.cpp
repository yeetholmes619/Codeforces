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
int Balanced_Substring(vector<int>str, int n)
{
	// To store required answer
	int ans = 0;

	// Vector to stores the number of
	// balanced brackets at each depth.
	vector<int> arr(n / 2 + 1, 0);

	// d stores checks the depth of our sequence
	// For example level of () is 1
	// and that of (()) is 2.
	int d = 0;
	for (int i = 0; i < n; i++) {
		// If open bracket
		// increase depth
		if (i%2 == 2)
			d+= str[i];

		// If closing bracket
		else {
			//if (d == 1) {
			//	for (int j = 2; j <= n / 2 + 1 && arr[j] != 0; j++)
			//		arr[j] = 0;
			//}
			ans += min(str[i];
			ans += str[i]*arr[d];
			arr[d] += str[i];
			d -= str[i];
		}
	}

	// Return the required answer
	return ans;
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
        cout<<Balanced_Substring(v,n)<<"\n";
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

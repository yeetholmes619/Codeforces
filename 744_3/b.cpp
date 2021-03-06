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
void shift_1(vector<int> &s, int l, int r){
        int temp = s[l];
        vector<int> t;
        for(int i = l+1; i <= r; i++) t.pb(s[i]);
        for(int i = l; i < r; i++) s[i] = t[i-l];
        s[r] = temp;
}

void shift_complete(vector<int>&s, int l, int r){
        int temp = s[r];
        vector<int> t;
        for(int i = l; i < r; i++) t.pb(s[i]);
        for(int i = l+1; i <= r; i++) s[i] = t[i-l-1];
        s[l] = temp;

}
vector<int> v;
int n;
void take(){
        cin>>n;
        v.clear();
        v.resize(n);
        cinarr(v);
}

void solve(){
        take();
        int k = 0;
        vector<int> sorte = v;
        vector<vector<int>> moves;
        sort(allvec(sorte));
        for(int i = 0; i < n; i++){
                int cache = sorte[i];
                for(int j =i ; j < n; j++){
                        if(v[j] == cache){
                                if(i == j) break;
                                else{
                                        if(i < j){
                                                moves.pb(vector<int>{i,j,j-i});
                                                shift_complete(v,i,j);
//                                                debug(v);
                                                break;
                                        }
                                        else{
                                                moves.pb(vector<int>{j,i,1});
                                                shift_1(v,j,i);
  //                                              debug(v);
                                                break;
                                        }

                                }
                        }
                }
        }

//        debug(v);

        cout<<moves.size()<<"\n";
        for(int i =0 ; i < moves.size(); i++){
                cout<<moves[i][0]+1<<" "<<moves[i][1]+1<<" "<<moves[i][2]<<"\n"; 
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

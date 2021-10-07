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
void debug(vector<string>v){
        for(auto t: v) cerr<<BR<<t<<"\n";
        cerr<<RESET;
        cerr<<"\n";
}
int n,m;
vector<string> v;
vector<vector<int>>zeros;
vector<vector<int>>zerosd; 
vector<vector<int>> one ;
vector<vector<int>> area_zero;
void take(){
        v.clear();
        cin>>n>>m;
        v.resize(n);
        cinarr(v);
        zeros.resize(n,vector<int>(m,0));
        zerosd.resize(n,vector<int>(m,0));
        one.resize(n,vector<int>(m,0));
        area_zero.resize(n,vector<int>(m,0));
}
int check(int x, int y, int a, int b){
        int cost = 0;
      //  for(int i = x+1; i < x+a-1; i++){
      //          if(v[i][y] == '0') cost++;
      //          if(v[i][y+b-1] == '0') cost++;

      // }

        cost += zerosd[x+a-2][y] - zerosd[x][y];
        cost += zerosd[x+a-2][y+b-1] - zerosd[x][y+b-1];
       // for(int j = y+1; j < y+b-1; j++){
       //         if(v[x][j] == '0') cost++;
       //         if(v[x+a-1][j] == '0') cost++;
       // }
       cost += zeros[x][y+b-2] - zeros[x][y];
       cost += zeros[x+a-1][y+b-2] - zeros[x+a-1][y];
       // for(int i = x+1; i< x+a-1; i++){
       //         for(int j = y+1; j < y+b-1; j++){
       //                 if(v[i][j] == '1') cost++;
       //         }
       // }
       cost += area_zero[x+a-2][y+b-2] - area_zero[x+a-2][y] - area_zero[x][y+b-2] + area_zero[x][y];
        return cost;
}
void solve(){
        take();
//        debug(v);
        int ans = INF;
        for(int j = 0; j < n; j++){
                if(v[j][0] == '1') one[j][0]++;
                if(v[j][0] == '0') zeros[j][0]++;
        }
        for(int j = 0; j < m; j++) zerosd[0][j] += v[0][j] == '0';
        for(int j =0 ; j < m; j++){
                for(int i = 1; i < n; i++){
                        zerosd[i][j] = zerosd[i-1][j] + (v[i][j] == '0');
                }
        }
        for(int i = 0; i < n; i++){
                for(int j = 1 ; j < m; j++){
                        one[i][j] = one[i][j-1] + (v[i][j] == '1');
                        zeros[i][j] = zeros[i][j-1] + (v[i][j] == '0');
                }
        }
        for(int j = 0; j < m; j++) area_zero[0][j] = one[0][j];
        for(int i =1; i < n; i++){
                for(int j = 0; j < m; j++){
                        area_zero[i][j] = area_zero[i-1][j] + one[i][j];
                }
        }
//        for(auto t: one) debug(t);
//        cerr<<"\n";
//        for(auto t: zeros) debug(t);
//        cerr<<"\n";
//        for(auto t: area_zero) debug(t);
//        cerr<<"\n";
        for(int a = 5; a <= n; a++){
                for(int b = 4; b <= m; b++){
                        for(int i = 0; i <= n-a; i++){
                                for(int j = 0; j <= m-b; j++){
                                        ans = min(ans,check(i,j,a,b));
                                }
                        }
                }
        }
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
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

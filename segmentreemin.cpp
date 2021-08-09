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
vector<long long> tree;
long long mid(long long a, long long b){ return (a+b)/2;}

long long getMin(int node,int node_low,int node_high,int query_low, int query_high){
        if((query_low <= node_low)&&(query_high >= node_high)) return tree[node];
        if((query_low > node_high)||(query_high < node_low)) return INT_MAX;
        return min(getMin((node*2), node_low, mid(node_low,node_high),query_low,query_high), getMin(((node*2)+1), mid(node_low,node_high)+1, node_high,query_low,query_high));
}
void change_rec(int node,int node_low,int node_high,int query_low, int query_high,int v){
        if((query_low <= node_low)&&(query_high >= node_high)){
                tree[node] = v;
                return;
        }
        if((query_low > node_high)||(query_high < node_low)) return;
        change_rec((node*2), node_low, mid(node_low,node_high),query_low,query_high,v);
        change_rec(((node*2)+1), mid(node_low,node_high)+1, node_high,query_low,query_high,v);
        tree[node] = min(tree[node*2] ,tree[node*2+1]);
}
void change(int pos,long long updated_val, int n){
        int i = n + pos;
        tree[i] = updated_val;
        i=i/2;
        while(i != 0){
                tree[i] = min(tree[2*i] ,tree[2*i+1]);
                i /= 2;
        }
}
void debug(vector<int> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}

void buildtree(vector<int> a, int &n){
        //make a power of 2
        while(__builtin_popcount(n) != 1){
                a.push_back(INT_MAX);
                n++;
        }

        //construct tree
        tree.resize(2*n);
        for(int i = 0; i <= n-1; i++) tree[n+i] = a[i];
        for(int i = n-1; i >=1; i--) tree[i] = min(tree[i*2] , tree[(i*2)+1]);
}

void take(){
}

void solve(){
        take();
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	for(int i = 0 ;i  < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

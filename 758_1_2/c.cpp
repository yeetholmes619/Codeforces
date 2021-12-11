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
#define fu(i,n) for(int i = 0; i < n; i++)
#define fu1(i,n) for(int i = 1; i <= n; i++)
#define fd(i,n) for(int i = n-1; i > -1; i--)
#define fd1(i,n) for(int i = n ; i >= 1; i--)
#define vi vector<int>
#define vs vector<string>
#define pi pair<int,int>
#define umap unordered_map
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
/**
 * I/O
 **/
#define int long long
#define output(value) cout << value << "\n"
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
void take(vector<T> &v, int &n){
        cin>>n;
        v.resize(n);
        cinarr(v);
}
template<class T>
void take(vector<vector<T>> &v, int &n, int &m ){
        cin>>n>>m;
        v.resize(n,vector<T>(m));
        for(int i =0 ;i < n; i++){
                for(int j = 0; j < m; j++){
                        cin>>v[i][j];
                }
        }
}

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\DEBUG/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n"<<RESET;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr <<BR<< "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void xr(int a, int b, int&c){
        c = a^b;
}
void mini(int a, int b, int&c){
        c = min(a,b);
}
void combine(int a, int b, int &c){
	c = a+b;
}
int mid(int a, int b){
	return a + (b-a)/2;
}
template<typename T>
class segtree{
	private:
	vector<T> tree;
	T neutral;
	void (*merge)(T, T, T&);
	int size;
	void build(vector<T> in){
		for(int i = 0; i < size; i++){
			tree[size+i-1] = in[i];
		}
		for(int i = size-2; i > -1; i--){
			merge(tree[2*i+1],tree[2*i + 2], tree[i]);
		}
	}

	T query(int node, int node_start, int node_end, int query_start, int query_end){
        if(node_end < node_start) return neutral;
		if((query_end< node_start) or (query_start > node_end)) return neutral;
		if((query_start == node_start) and (query_end == node_end)) return tree[node];
        if(((query_start == node_start) and (query_end > node_end)) or ((query_start < node_start) and (query_end == node_end))) return tree[node];
        if((query_start <= node_start) and (query_end >= node_end)) return tree[node];
		T answer;
		merge(query(2*node +1, node_start, mid(node_start,node_end),query_start,query_end),query(2*node +2, mid(node_start,node_end)+1,node_end,query_start,query_end), answer);
		return answer;
	}
    
    void fix(int node){

            merge(tree[node*2 + 1], tree[ node*2 + 2],tree[node]);
            if(node == 0) return;
            fix((node - 1)/2);
    }

	public:
	segtree(vector<T> in ,T neu,void (*fun)(T,T,T&) = &combine){
		size = in.size();
		neutral = neu;
		merge = fun;
		while(__builtin_popcount(size) != 1){
			size++;
			in.pb(neutral);
		}
		tree.resize(2*size - 1,neutral);
		build(in);
	}
	segtree(int n, T neu, void (*fun)(T, T, T&)  = &combine){
		size = n;
		neutral = neu;
		merge = fun;
		while(__builtin_popcount(n) != 1){
			size++;
		}
		tree.resize(2*size - 1,neutral);
	}
	T query(int start, int end){
		return query(0, 0, size-1, start, end);
	}
    void update(int pos, T new_val){
            tree[size-1+pos] = new_val;
            if(size != 1) fix((size-2+pos)/2);
    }
};
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
int n;
vector<pair<int,int>> a;
vector<pair<int,int>> b;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void take(){
        cin>>n;
        a.resize(n);
        b.resize(n);
        for(int i = 0; i < n; i++){
                cin>>a[i].first;
                a[i].second = i;
        }
        for(int i = 0; i < n; i++){
                cin>>b[i].first;
                b[i].second = i;
        }
}

void solve(){
        take();
        sort(allvec(a));
        sort(allvec(b));
        map<int,int> m1,m2;
        for(int i = 0; i < n; i++){
                m1[a[i].second] = i;
        }
        for(int i  =0; i < n; i++){
                m2[b[i].second] = i;
        }
        vector<int> one;
        vector<int> two;
        for(auto t: a){
                one.pb(m2[t.second]);
        }
        for(auto t: a){
                two.pb(m1[t.second]);
        }
        debug(one);
        debug(two);
        segtree<int> st1(one,10000000000,mini);
        segtree<int> st2(two,10000000000,mini);
        int curr1 = n-1;
        int curr2 = st1.query(curr1,n-1);
        for(int i =  1;  i<= n+3; i++){
                curr1 = st2.query(curr2,n-1);
                curr2 = st1.query(curr1,n-1);
                curr1 = st2.query(curr2,n-1);
        }
        string ans = string(n,'0');
        for(int i = curr1; i < n; i++){
                ans[a[i].second] = '1';
        }
        cout<<ans<<"\n";
        
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	cin >> t;
	for(int i = 1 ; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

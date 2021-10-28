//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
template<class T>
void debug(vector<T> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
vector<int> dp;
vector<int> a;
vector<int> b;
map<int,bool> visited;
map<int,bool> processing;

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
void xr(int a, int b, int&c){
        c = a^b;
}
void mini(int a, int b, int&c){
        c = min(a,b);
}
void combine(int a, int b, int &c){
	c = a+b;
}
void min(pair<int,int> aa, pair<int,int> bb, pair<int,int>& cc){
        if(dp[aa.second+b[aa.second]] <=dp[bb.second + b[bb.second]]){
                cc = aa;
        }
        else cc = bb;
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
	segtree(vector<T> &in ,T neu,void (*fun)(T,T,T&) = &combine){
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
int n;
int rec(int index){
//        cerr<<index<<"\n";
        if(visited[index] == true) return dp[index];
        if(index == 0) return 0;
        processing[index] = true;
        int k = MOD;
        for(int i = index-1; i >= index - a[index]; i--){
                if((i + b[i] != index) and (!processing[i+b[i]]))k = min(k,rec(i + b[i]));
        }
        processing[index] = false;
        dp[index] = 1 + k;
        visited[index] = true;
//        cerr<<index<<" "<<dp[index]<<"\n";
        return dp[index];
}
void fill(){
        dp[0] = 0;
        rec(n);
}
vector<int> getPath(){
        vector<pair<int,int>> p;
        for(int i = 0; i <= n; i++){
                p.pb({dp[i],i});
        }
        segtree<pair<int,int>> st(p,p.back(),min);
        vector<int> ans;
        int s = dp[n];
        int prev = n;
        for(int i = 0; i < s; i++){
                ans.pb((st.query(prev - a[prev], prev-1)).second);
                prev = ans.back();
        }
        ans[ans.size()-1] = 0;
        return ans;
}

void take(){
        cin>>n;
        dp.resize(n+1,MOD);
        visited.clear();
        a.resize(n+1,0);
        b.resize(n+1,0);
        for(int i = 1; i < n+1; i++) cin>>a[i];
        for(int i = 1; i < n+1; i++) cin>>b[i];
}
void solve(){
        take();
        fill();
//        debug(dp);
        if(dp[n] >= 1e9) {cout<<-1; return;}
        cout<<dp[n]<<"\n";
        vector<int> path = getPath();
        _print(path);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
//	cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

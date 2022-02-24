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
#define fu(i,a,b) for(int i = a; i <= b; i++)
#define fd(i,a,b) for(int i = a; i >= b; i--)
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>
#define mci map<char,int>
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define sz(x) (int)(x.size())
#define left asdgashgrketwjklrej
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd
#define prev asdgSHJsfgsdfhdsh
#define umap unordered_map
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
#define int long long
#define output(value) cout << value << "\n"
#define error(errorString) cout << BR << errorString << RESET<< "\n"
#define info(infoString) cout << BB << infoString << RESET << "\n"
#define success(successString) cout << BB << successString << RESET << "\n"
#define allarr(a,n) a, a+n
const int mod1 =1000000007;
const int mod2 = 998244353;
// precedence order :- double > float > long long int > long int > int > char
// remember that boolean arrays and variables if uninitialized are given false
// say x is a character, s += x is faster than s = s+x
//Check if constraints are correct
// for single arrays declare them as long long int
//overflow must be taken care of!! use strings when big
//	0 < |int| < 1e9
//	0 < |long long int| < 1e18
//when you are working with stacks, remember to take care of stacks of 0 size
//when you see a problem, and you know how you would tackle it in the real world, but don't know how
//you would do it in code, go step by step, in each step try to be concious of what you want to do
//and once you have done so, review through and remember what data structure would be perfect
//when we pass an array in a function the pointer is passed but when we pass a vector, a copy is passed
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); } 
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
	for (auto &it : v)
		cin >> it;
	return istream;
}
 
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\GLOBAL VARIABLES/\/\/\/\/\/\/\/\/\/\/\/\///\/\/
int n;
vi v;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/
void mx(int a, int b, int &c){
        c = max(a,b);
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
            fix((size-2+pos)/2);
    }
};
int fun()
{
        vi arr = v;
    // to store the minimum value that is ending
    // up to the current index
    int min_ending_here = INT_MAX;
     
    // to store the minimum value encountered so far
    int min_so_far = INT_MAX;
     
    // traverse the array elements
    for (int i=2; i<n-2; i++)
    {
        // if min_ending_here > 0, then it could not possibly
        // contribute to the minimum sum further
        if (min_ending_here > 0)
            min_ending_here = arr[i];
         
        // else add the value arr[i] to min_ending_here   
        else
            min_ending_here += arr[i];
         
        // update min_so_far
        min_so_far = min(min_so_far, min_ending_here);           
    }
     
    // required smallest sum contiguous subarray value
    return min_so_far;
}
void take(){
        cin>>n;
        v.resize(n);
        cin>>v;
}

void solve(){
        take();
        debug(n,v);
        vi vf =v;
        vi ve = v;
        int ans = 0LL;
        for(int i = 1; i < n; i++){
                vf[i] += vf[i-1];
        }
        int k = fun();
        ans = max(ans,vf[n-1]-k);

        for(int i  =n-2; i > -1; i--){
                ve[i] += ve[i+1];
        }
       // debug(vf,ve);
       // segtree<int> f(vf,INT_MIN,mx);
       // segtree<int> e(ve,INT_MIN,mx);
       // int ans =0LL;
       // for(int i = 1; ((i+1 <= n-2)); i++){
       //         ans = max(ans,f.query(1LL,i)+e.query(i+1,n-2));
       // }
        for(int  i= 1; i < n; i++){
                ans = max(ans,vf[i]);
        }
        for(int i = n-2; i > -1; i--){
                ans = max(ans,ve[i]);
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
#ifdef DEBUG
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
#endif
}

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
vi dist_frnd;
vi dist_person;
vi friends;
int n,k;
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\///\/\/\/\/\/\/

class Graph{
        public:
//        map<int,vector<int>>adj;
//        map<int,bool> visited;
//        map<int,int> color;
        vector<vector<int>> adj;
        vector<bool> visited;
        vector<int> color;
        int n;
        Graph(int x = 1){
                n = x;
                adj.resize(n+1);
                visited.resize(n+1,false);
                color.resize(n+1,-1);
        }


        void addEdge(int f, int t);

        void dfs(int a);
        void dfs_main(int a);

        void bfs(int b);
        void multibfs(vector<int>& v);
};

void Graph::multibfs(vector<int>& v){
        visited.clear();
        visited.resize(n+1,false);
        queue<int> q;
        for(auto t: v){
                //cout<<t<<" ";
                debug(t);
                q.push(t);
                visited[t] = true;
                dist_frnd[t] = 0;
        }
        debug(dist_frnd);
        while(q.size() != 0){
                int s = q.front();
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        debug(t);
                        dist_frnd[t] = min(dist_frnd[t],dist_frnd[s]+1);
                        //cout<<t<<" ";
                        q.push(t);
                }
        }

        return;
}


void Graph:: addEdge(int f, int t){
        adj[f].pb(t);
        return;
}

void Graph::dfs_main(int a){
        visited[a] = true;
        //cout<<a<<" ";
        for(auto t : adj[a]){
                if(visited[t]) continue;
                dfs(t);
        }
        return;
}

void Graph::dfs(int a){
        visited.clear();
        visited.resize(n+1,false);
        dfs(a);
        return;
}

void Graph::bfs(int b){

        queue<int> q;
        visited.clear();
        visited.resize(n+1,false);
        visited[b] = true;
        dist_person[b] = 0;
        //cout<<b<<" ";
        q.push(b);
        while(q.size() != 0){
                int s = q.front();
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        dist_person[t] = min(dist_person[s]+1,dist_person[t]);
                        //cout<<t<<" ";
                        q.push(t);
                }
        }

        return;
}
void take(){
        cin>>n>>k;
        friends.clear();
        friends.resize(k);
        cin>>friends;
}

void solve(){
        take();
        debug(friends);
        dist_frnd.clear();
        dist_person.clear();
        dist_frnd.resize(n+1,INT_MAX);
        dist_person.resize(n+1,INT_MAX);
        Graph g(n);
        vi ord(n+1,0LL);
        for(int i = 0; i < n-1; i++){
                int a,b;
                cin>>a>>b;
                g.addEdge(a,b);
                ord[a]++;
                g.addEdge(b,a);
                ord[b]++;
        }
        g.multibfs(friends);
        g.bfs(1);
        debug(dist_person);
        debug(dist_frnd);
        for(int i= 2; i <= n; i++){
                if(ord[i] == 1){
                        if(dist_frnd[i] > dist_person[i]){
                                cout<<"YES\n";
                                return;
                        }
                }
        }
        cout<<"NO\n";
        return;

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

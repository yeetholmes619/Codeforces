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
template<class T>
void debug(vector<T> v){
        for(auto t: v) cerr<<BR<<t<<" "<<RESET;
        cerr<<"\n";
}
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

class Graph{
        public:
        map<int,int> o;
        map<int,vector<int>>adj;
        map<int,bool> visited;
        map<int,int> color;

        bool isBipartite(int a);

        void addEdge(int f, int t);

        void dfs(int a);

        void bfs(int b);
};


void Graph:: addEdge(int f, int t){
        adj[f].pb(t);
        visited[f] = false;
        visited[t] = false;
        o[f]++;
        color[f] = -1;
        color[t] = -1;
        return;
}

void Graph::dfs(int a){
        visited[a] = true;
        //cout<<a<<" ";
        for(auto t : adj[a]){
                if(visited[t]) continue;
                dfs(t);
        }
        return;
}

void Graph::bfs(int b){

        queue<int> q;
        for(auto &t: visited) t.second = false;
        visited[b] = true;
        //cout<<b<<" ";
        q.push(b);
        while(q.size() != 0){
                int s = q.front();
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        //cout<<t<<" ";
                        q.push(t);
                }
        }

        return;
}

bool Graph:: isBipartite(int a = 1){
                for(auto &t: visited) t.second = false;
                queue<int> q;
                q.push(a);
                color[a] = 1;
                visited[a] = true;
                while(q.size() != 0){
                        int last = q.front();
                        q.pop();
                        for(auto t: adj[last]){
                                if(color[t] == -1) color[t] = color[last]==1?0:1;
                                else if(color[t] == color[last]) return false;
                                if(visited[t] != true){
                                        visited[t] = true;
                                        q.push(t);
                                }
                        }
                }

                return true;
}
int n,k;
void take(){
        cin>>n>>k;
}

void solve(){
        take();
        Graph g;
        for(int i = 1; i < n; i++){
                int a,b;
                cin>>a>>b;
                g.addEdge(a,b);
                g.addEdge(b,a);
        }
        vector<int> ans(n,0);
        for(int i = 1; i <= n; i++){
                ans[g.o[i]]++;
        }
        vector<int> dd;
        for(auto t: ans) if(t != 0) dd.pb(t);
        int nn = dd.size();
        int fin = 0;
        for(int i = 1; i <= min(nn,k); i++){
                fin += dd[i-1];
        }
        cout<<n-fin<<"\n";
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


//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]

#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
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
#define allvec(v) v.begin(), v.end()
#define vstr vector<string>
#define vll vector<ll>
#define vint vector<int>
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
void debug(vector<int> v) {
        for(auto t: v) cerr<<t<<" "; 
        cerr<<"\n";
}

using namespace std;

class Graph{
        public:
        map<int,vector<int>>adj;
        map<int,bool> visited;
        void addEdge(int f, int t);

        void dfs(int a);

        void bfs(int b);
        void bfs2(int b,int target, vector<int>&vp);
        bool dfs2(int b, int x,int target);
};


void Graph:: addEdge(int f, int t){
        adj[f].pb(t);
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
int n,k;
vector<int> v;
void Graph::bfs2(int b,int target, vector<int>&vp){
        int start = 0;
        queue<pair<int,int>> q;
        for(auto &t: visited) t.second = false;
        visited[b] = true;
        //cout<<b<<" ";
        start ^= v[b-1];
        if(start == target) vp.pb(b);
        q.push({start,b});
        while(q.size() != 0){
                int s = (q.front()).second;
                int temp = (q.front()).first;
                q.pop();
                for(auto t: adj[s]){
                        if(visited[t]) continue;
                        visited[t] = true;
                        //cout<<t<<" ";
                        if((temp^v[t-1]) == target) vp.pb(t);
                        q.push({(temp^v[t-1]),t});
                }
        }

        return;
}
bool Graph::dfs2(int a,int x,int target=0){
        visited[a] = true;
        if((x^v[a-1]) == target) return true;
        x ^= v[a-1];
        //cout<<a<<" ";
        for(auto t : adj[a]){
                if(visited[t]) continue;
                if(dfs2(t,x)) return true;
        }
        return false;
}

void take(){
        v.clear();
        cin>>n;
        cin>>k;
        v.resize(n);
        cinarr(v);
}
void solve() {
        take();
        Graph g;
        for(int i = 0; i < n-1; i++){
                int a,b;
                cin>>a>>b;
                g.addEdge(a,b);
        }
        int start =0;
        for(int i =0 ; i < n; i++) start ^= v[i];
        if(start == 0){
                cout<<"YES\n";
                return;
        }
        else if(k == 2){
                cout<<"NO\n";
                return;
        }
        vector<int> candidate;
        g.bfs2(1,start,candidate);
        if(candidate.size() == 0){
                cout<<"NO\n";
                return;
        }
//        debug(candidate);
        for(auto t: candidate){
                for(auto l: g.adj[t]){
                        (g.visited).clear();
                        if(g.dfs2(l,0,start)){
                                cout<<"YES\n";
                                return;
                        }
                }
        }
        cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
//		cout << "Case #" << i << ": ";
		solve();
	}
}

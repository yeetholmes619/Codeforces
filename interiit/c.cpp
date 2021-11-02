
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

using namespace std;

class Graph{
        public:
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
int n,m,k;
void take(){
        cin>>n>>m>>k;
}

void solve() {
        take();
        Graph g;
        vector<int> ord(n+1,0);
        for(int i = 0; i < m; i++){
                int a,b;
                cin>>a>>b;
                g.addEdge(a,b);
                g.addEdge(b,a);
                ord[a]++;
                ord[b]++;
        }
        g.dfs(k);
        for(int i = 1; i<= n; i++){
                if((g.visited[i] == false) and ((g.adj[i]).size() != 0)){
                        cout<<"NO\n";
                        return;
                }
        }
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
                if(ord[i+1]%2) odd++;
                else even++;
        }
        if(odd == 0){
                cout<<"YES\n";
                return;
        }
        if((odd <= 2) and (ord[k]%2 == 1)){
                cout<<"YES\n";
                return ;
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

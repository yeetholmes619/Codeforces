
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
map<int,int> dis;
map<int,int> pos;
class Graph{
        public:
        map<int,vector<int>>adj;
        map<int,bool> visited;
        map<int,int> color;

        bool isBipartite(int a);

        void addEdge(int f, int t);

        void dfs(int a, int distance);

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

void Graph::dfs(int a,int distance){
        visited[a] = true;
        dis[a] = distance;
        for(auto t : adj[a]){
                if(visited[t]) continue;
                dfs(t,distance + max(pos[t] - pos[a],0));
        }
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
int n;
vector<int> ances;
vector<int> v;
void take(){
        cin>>n;
        ances.resize(n);
        v.resize(n);
        cinarr(ances);
        cinarr(v);
        dis.clear();
        pos.clear();
}

void solve() {
        take();
        Graph g;
        int root = -1;
        for(int i = 1; i <= n; i++){
                pos[v[i-1]] = i;
                if(ances[i-1] == i) root = i;
                else g.addEdge(ances[i-1],i);
        }
        g.dfs(root,0);
//        for(int i = 1; i <= n; i++){
//                cerr<<BOLDRED<<dis[i]<<" ";
  //              cerr<<RESET;
  //      }
   //     cerr<<"\n";
        for(int i = 1; i < n; i++){
                if(dis[v[i]] <= dis[v[i-1]]){
                        cout<<-1<<"\n";
                        return;
                }
        }
        for(int i = 1; i <= n; i++){
                cout<<dis[i]-dis[ances[i-1]]<<" ";
        }
        cout<<"\n";


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

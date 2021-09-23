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
#define fu(i,a,b) for(ll i = a; i<=b;i++)
#define fd(i,a,b) for(ll i = a; i>=b; i--)
#define fdd(i,a) for(ll i = a; i>=1; i--)
#define fuu(i,a)for(ll i = 1; i<=a; i++)
#define pb push_back
#define pf push_front
#define cinarr(a) for(auto &zz:a)cin>>zz
#define mp make_pair
#define allvec(v) v.begin(), v.end()
#define vstr vector<string>
#define vll vector<ll>
#define vint vector<int>
/**
 * I/O
 **/
using namespace std;
#define int long long
#define output(value) cout << value << endl
#define error(errorString) cout << BR << errorString << RESET<< " "
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
class Graph{
        //break time;
                bool findtopo(int node, map<int,int>& status, vector<int> & result);
        public:
                int n;
                map<int,vector<int>> adj;
                vector<int> toposort();
                void addEdge(int a, int b);
                Graph(){
                        n = 0;
                }
                Graph(int k){
                        n = k;
                }
};
void Graph::addEdge(int a, int b){
        adj[a].pb(b);
}
bool Graph::findtopo(int node, map<int,int> &status, vector<int> &result){
        if(status[node] == 0) status[node] = 1; 
        else return false;
//        priority_queue<int> pq;
//        for(auto t: adj[node]) pq.push(-1*t);
//        while(pq.size()){
//                int t = pq.top(); pq.pop();
//                t *= -1;
          for(auto t: adj[node]){
                if(status[t] != 2){
                        bool check  = findtopo(t,status,result);
                        if(!check) return false;
                }
        }
        status[node] = 2;
        result.pb(node);
        return true;
}
vector<int> Graph::toposort(){
        vector<int> answer;
        map<int,int> status;
        for(int i = 1; i <= n; i++){
                if(status[i] != 2){
                        bool check = findtopo(i,status,answer);
                        if(!check){
                                answer.clear();
                                return answer;
                        }
                }
        }
        reverse(allvec(answer));
        return answer;
}

void debug(vector<int> v){
        for(auto t: v) error(t<<" ");
        cerr<<"\n";
}
int n;
void take(){
        cin>>n;
}

void solve(){
        take();
        Graph g;
        g.n = n;
        for(int i =0; i < n ; i++){
                int k;
                cin>>k;
                for(int j = 0; j < k; j++){
                        int t;
                        cin>>t;
                        g.addEdge(t,i+1);
                }
        }
        vector<int> res =  g.toposort();
        //debug(res);
        if(res.size() == 0){
                cout<<-1<<"\n";
                return;
        }
        else {
                vector<int> dp(n+1,1);
                int ans = -1;
                for(int i = 0; i  < n; i++){
                      //  priority_queue<int> pq;
                      //  for(auto t: g.adj[res[i]]) pq.push(-1*t);
                      //  while(pq.size()){
                      //          int t = -1*pq.top();pq.pop();
                          for(auto t: g.adj[res[i]]){
                                if(t < res[i]) dp[t] = max(dp[t],dp[res[i]] + 1);
                                else dp[t] = max(dp[t],dp[res[i]]);
                                //dp[t] = max(dp[t],dp[res[i]] + 1);
                                //if(t > res[i]) dp[t] = max(dp[t],dp[res[i]] + 1);
                        }
                }
                //debug(dp);
                for(auto t: dp) ans = max(ans,t);
                cout<<ans<<"\n";
        }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}


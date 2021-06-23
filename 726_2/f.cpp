#include<bits/stdc++.h>
using namespace std;

class Graph{
        public:
        map<int,vector<int>> adj;
        map<int,bool> visited;
        map<int,int> initial;
        map<int,int> target;
        map<int,int> color;
        long long sum_blue;
        long long sum_red;

        void addEdge(int a, int b);
        bool isBipartite(int a);
};

void Graph::addEdge(int a, int b){
        adj[a].push_back(b);
        return;
}

bool Graph::isBipartite(int a){
                queue<int> q;
                q.push(a);
                color[a] = 1;
                sum_red = 0;
                sum_blue = 0;
                sum_red += target[a] - initial[a];
                visited[a] = true;
                while(q.size() != 0){
                        int last = q.front();
                        q.pop();
                        for(auto t: adj[last]){
    //                            assert(color[last] != -1);
                                if(color[t] == -1) color[t] = color[last]==1?0:1;
                                else if(color[t] == color[last]) return false;
                                if(visited[t] != true){
                                        visited[t] = true;
                                        if(color[t] == 1){
                                                sum_red += target[t] - initial[t] ;
                                        }
                                        else if(color[t] == 0){
                                                sum_blue += target[t] - initial[t];
                                        }
                                        else{
                                                assert(false);
                                        }

                                        q.push(t);
                                }
                        }
                }

                return true;
}
void solve(){
                Graph g;
  //              assert(g.adj.size() == 0);
//                assert(g.sum_blue == 0);
                int n,m;
                long long sum_initial = 0;
                long long sum_target = 0;
                cin>>n>>m;
                for(int i = 1; i <= n; i++) g.color[i]= -1;
                for(int i = 1; i <=n; i++) {
                        cin>>g.initial[i];
                        sum_initial += g.initial[i];
                }
                for(int i = 1; i <=n; i++){
                         cin>>g.target[i];
                         sum_target += g.target[i];
                }
                for(int i = 1; i <= m; i++){
                        int a,b;
                        cin>>a>>b;
                        g.addEdge(a,b);
                        g.addEdge(b,a);
                }
                if(abs(sum_target)%2 != abs(sum_initial)%2){
                         cout<<"NO\n";
                         return;
                }
                if(g.isBipartite(1)){
                        if(g.sum_red == g.sum_blue){
                                cout<<"YES\n";
                                return;
                        }
                        else{
                                cout<<"NO\n";
                                return;
                        }
                }
                else{
                        cout<<"YES\n";
                        return;
                }
}

int main(){
        int t = 1;
        cin>>t;
        for(int tt = 0; tt < t; tt++){
                solve();
        }
}


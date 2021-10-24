//
//  main.cpp
//  main2
//
//  Created by Rajveer Singh on 23/09/21.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cstring>

//MARK:- PRACTICE

#define len(a) (ll)a.size()
typedef long long ll;
typedef long double ld;

bool test=true;
ll mod1=1e9+7;
ll mod2=998244353;
ll inf=1e10+5;

void testCase() {
    
    ll n, k;
    
    std::cin>>n>>k;
    
    std::vector<std::vector<ll>> adj(n+1);
    
    for(int i=0;i<=n-2;i++) {
        
        ll u, v;
        std::cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    std::vector<ll> deg(n+1), cnt(n+1, 0);
    std::set<ll> rem;
    
    for(int i=1;i<=n;i++) {
        
        deg[i]=len(adj[i]);
        
        if(deg[i]<=1) {
            
            rem.insert(i);
        }
    }
    
    ll cur=1;
    
    while(!rem.empty()) {
        
        std::set<ll> r;
        
        for(ll i: rem) {
            
            deg[i]=-2;
            cnt[i]=cur;
            
            for(ll j: adj[i]) {
                
                deg[j]--;
                
                if(deg[j]<=1 && deg[j]>=0 && rem.find(j)==rem.end()) {
                    
                    r.insert(j);
                }
            }
        }
        
        rem=r;
        cur++;
    }
    
    ll c=0;
    
    for(int i=1;i<=n;i++) {
        
        if(cnt[i]>k) {
            
            c++;
        }
    }
           
    std::cout<<c<<"\n";
}

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.precision(15);
    
    ll t=1;
    
    if(test) {
        
        std::cin>>t;
    }
    
    for(ll i=0;i<=t-1;i++) {
        
        //        std::cout<<"Case #"<<i+1<<": ";
        testCase();
    }
}


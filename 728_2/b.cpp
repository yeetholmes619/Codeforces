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
struct each{
        ll val;
        ll index;
};
ll n;
vector<each> v;
bool comp(each a, each b){
        if(a.val >= b.val) return true;
        return false;
}
void take(){
        v.clear();
        cin>>n;
        v.resize(n);
        for(int i = 0; i < n; i++){
                cin>>v[i].val;
                v[i].index = i+1;
        }
}

void solve(){
        take();
        sort(v.begin(),v.end(),comp);
        set <set<ll>> s;
        for(ll  i = 0; i < n; i++){
                ll start = 0;
                ll end = n-1;
                ll mid = (start+end)/2;
                while(start <= end){
                        if(v[i].val * v[mid].val == v[i].index + v[mid].index){
                                if(i != mid)
                                s.insert({v[i].index,v[mid].index});
                                break;
                        }
                        if(start == end) break;
                        if(v[i].val * v[mid].val < v[i].index + v[mid].index){
                                end = mid-1;
                                mid = (start+end)/2;
                        }
                        if(v[i].val * v[mid].val > v[i].index + v[mid].index){
                                start = mid+1;
                                mid = (start+end)/2;
                        }
                }
                 start = 0;
                 end = n-1;
                 mid = (start+end)/2;
                while(start <= end){
                        if(v[i].val * v[mid].val == v[i].index + v[mid].index){
                                if(i != mid)
                                s.insert({v[i].index,v[mid].index});
                                break;
                        }
                        if(start == end) break;
                        if(v[i].val * v[mid].val > v[i].index + v[mid].index){
                                end = mid-1;
                                mid = (start+end)/2;
                        }
                        if(v[i].val * v[mid].val < v[i].index + v[mid].index){
                                start = mid+1;
                                mid = (start+end)/2;
                        }
                }
        }
        cout<<s.size()<<"\n";
}
                        
                



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t = 1;
	cin >> t;
	fuu(i, t) {
		//cout << "Case #" << i << ": ";
		solve();
	}
}

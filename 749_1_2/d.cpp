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
int n;
void take(){
        cin>>n;
}

void solve(){
        take();
        /**
        find the last digit.
        when I get and index > 0, then I
        **/
        vector<int> ans(n+1,-1);
        int resp;
        cout<<"? ";
        for(int i  =0; i < n-1; i++){
                cout<<1<<" ";
        }
        cout<<2<<endl;
        cin>>resp;
        if(resp == 0){
                ans[n] = n;
                for(int i = 0; i < n-1; i++){
                        cout<<"? "; 
                        for(int j = 0; j < n-1; j++){
                                cout<<n-i<<" ";
                        }
                        cout<<1<<endl;
                        cin>>resp;
                        ans[resp] = i+1;
                }
                cout<<"! ";
                for(int i =1; i<= n; i++){
                        cout<<ans[i]<<" ";
                }
                cout<<endl;
        }
        else{
                for(int x = 1; x <= n; x++){
                        cout<<"? ";
                        for(int i = 0; i < n-1; i++){
                                cout<<1<<" ";
                       }
                        cout<<n-x+1<<endl;
                        cin>>resp;
                        if(resp > 0){
                                ans[resp] = n;
                                ans[n] = x;
                                break;
                        }
                }
                int chad = resp;
                int x = ans[n];
                //greater than x
                for(int i = 1; x+i < n; i++){
                        cout<<"? ";
                        for(int j = 0; j < n-1; j++){
                                cout<<1<<" ";
                        }
                        cout<<i+1<<endl;
                        cin>>resp;
                        ans[resp] = x+i;
                }
                for(int i = 1; i<= x-1; i++){
                        cout<<"? ";
                        for(int j = 0; j < n-1; j++){
                                cout<<i+1<<" ";
                        }
                        cout<<1<<endl;
                        cin>>resp;
                        ans[resp] = x-i;
                }
                cout<<"! ";
                for(int i = 1; i <= n; i++){
                        cout<<ans[i]<<" ";
                }
                cout<<endl;
        }




}


int32_t main() {
    auto time0 = curtime;
	ll t = 1;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

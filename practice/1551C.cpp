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
struct obj{
        string word;
        int frequency[5];
        int WordSize;
        obj(){
                word = "";
                WordSize = 0;
                for(int i =0 ; i < 5; i++){
                        frequency[i] = 0;
                }
        }
};
void debug(obj v[],int sz){
        for(int i =0 ; i < sz; i++) cerr<<BR<<v[i].word<<" "<<RESET;
        cerr<<"\n";
}
void debug2(obj v[],int sz){
        for(int i =0 ; i < sz; i++){
                cerr<<BG<<v[i].word<<" "<<RESET;
                for(int j = 0; j < 5; j++){
                        cerr<<BR<<(v[i].frequency)[j]<<" "<<RESET;
                }
                cerr<<"\n";
        }
        cerr<<"\n";
}
const int SIZE = 200007;
obj in[200007];
int choice;
bool cmp(obj one, obj two){
        if(one.WordSize - 2*(one.frequency)[choice] > two.WordSize - 2*(two.frequency)[choice]) return true;
        if(one.WordSize - 2*(one.frequency)[choice] < two.WordSize -2*(two.frequency)[choice]) return false;
        return (one.frequency)[choice] < (two.frequency)[choice];
}
int arr[5];
int n;
void take(){
        cin>>n;
        for(int i = 0; i < 5; i++) arr[i] = 0;
        for(int i =0 ; i < n; i++){
                cin>>in[i].word;
                in[i].WordSize = (in[i].word).size();
                for(int j = 0; j < 5; j++){
                        (in[i].frequency)[j] = 0;

                }
                for(int j = 0; j < in[i].WordSize; j++){
                        (in[i].frequency)[(in[i].word)[j] - 'a']++;
                }
                for(int j = 0; j < 5; j++){
                        arr[j] += (in[i].frequency)[j];
                }
        }
}
void solve(){
        take();
       // debug2(in,n);
        int ans =0 ;
        int nc =0 ;
    //    for(int i = 0 ;i  < 5; i++) cerr<<BG<<arr[i]<<" ";
  //      cerr<<"\n"<<RESET;
        for(int i = 0 ;i  < 5; i++) nc += arr[i];
        for(int ch = 0; ch < 5; ch++){
                int pos = 0, neg = 0;
                pos = arr[ch];
                neg = nc - pos;
                if(pos > neg){
//                        cerr<<BB<<(char)(ch+'a')<<RESET<<"\n";
                        cout<<n<<"\n";
                        return;
                }
                choice = ch;
                sort(in, in + n, cmp);
      //          debug(in,n);
                for(int j = 0; j < n; j++){
                        int temp = (in[j].frequency)[ch];
                        pos -= temp;
                        neg -= in[j].WordSize - temp;
                        if(pos > neg){
                                ans = max(ans, n-j-1);
                                break;
                        }
                }
        }
        cout<<ans<<"\n";

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

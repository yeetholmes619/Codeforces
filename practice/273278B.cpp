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
void xr(int a, int b, int&c){
        c = a^b;
}
void mini(int a, int b, int&c){
        c = min(a,b);
}
void combine(int a, int b, int &c){
	c = a+b;
}
int mid(int a, int b){
	return a + (b-a)/2;
}
template<typename T>
class segtree{
	private:
	vector<T> tree;
	T neutral;
	void (*merge)(T, T, T&);
	int size;
	void build(vector<T> in){
		for(int i = 0; i < size; i++){
			tree[size+i-1] = in[i];
		}
		for(int i = size-2; i > -1; i--){
			merge(tree[2*i+1],tree[2*i + 2], tree[i]);
		}
//        debug(tree);
	}

	T query(int node, int node_start, int node_end, int query_start, int query_end){
        if(node_end < node_start) return neutral;
		if((query_end< node_start) or (query_start > node_end)) return neutral;
		if((query_start == node_start) and (query_end == node_end)) return tree[node];
        if(((query_start == node_start) and (query_end > node_end)) or ((query_start < node_start) and (query_end == node_end))) return tree[node];
        if((query_start <= node_start) and (query_end >= node_end)) return tree[node];
		T answer;
		merge(query(2*node +1, node_start, mid(node_start,node_end),query_start,query_end),query(2*node +2, mid(node_start,node_end)+1,node_end,query_start,query_end), answer);
		return answer;
	}
    
    void fix(int node){

            merge(tree[node*2 + 1], tree[ node*2 + 2],tree[node]);
            if(node == 0) return;
            fix((node - 1)/2);
    }
    int answer(int k, int node){
            if(node> size - 2){
                    return node - size + 1;
            }
            else{
                    if(tree[node*2 + 1]  < k){
                            return answer(k - tree[node*2 + 1],node*2 + 2);
                    }
                    else{
                            return answer(k,node*2 + 1);
                    }
            }
    }

	public:
    int answer(int k){
            return answer(k,0);
    }
	segtree(vector<T> in ,T neu,void (*fun)(T,T,T&) = &combine){
		size = in.size();
		neutral = neu;
		merge = fun;
		while(__builtin_popcount(size) != 1){
			size++;
			in.pb(neutral);
		}
		tree.resize(2*size - 1,neutral);
		build(in);
	}
	segtree(int n, T neu, void (*fun)(T, T, T&)  = &combine){
		size = n;
		neutral = neu;
		merge = fun;
		while(__builtin_popcount(n) != 1){
			size++;
		}
		tree.resize(2*size - 1,neutral);
	}
	T query(int start, int end){
		return query(0, 0, size-1, start, end);
	}
    void update(int pos, T new_val){
            tree[size-1+pos] = new_val;
            if(size != 1) fix((size-2+pos)/2);
    }
};
int n,m;
vector<int> v;
void take(){
        cin>>n>>m;
        v.resize(n);
        cinarr(v);
}
void solve(){
        take();
        segtree<int> st(v,0);
        while(m--){
                int choice;
                cin>>choice;
                if(choice == 1){
                        int index;
                        cin>>index;
                        st.update(index, 1^(st.query(index,index)));
                }
                else{
                        int k;
                        cin>>k;
                        cout<<st.answer(k+1)<<"\n";
                }
        }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto time0 = curtime;
	ll t = 1;
	//cin >> t;
	for(int i = 0 ; i < t; i++) {
		//cout << "Case #" << i << ": ";
		solve();
	}
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

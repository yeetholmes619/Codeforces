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
//  0 < |int| < 1e9
//  0 < |long int| < 1e12
//  0 < |long long int| < 1e18
//when you are working with stacks, remember to take care of stacks of 0 size
//when you see a problem, and you know how you would tackle it in the real world, but don't know how
//you would do it in code, go step by step, in each step try to be concious of what you want to do
//and once you have done so, review through and remember what data structure would be perfect
//when we pass an array in a function the pointer is passed but when we pass a vector, a copy is passed
long long power_mod(long long a, long long b,long long m = MOD){
        if(b == 0) return 1LL;
        if(b == 1) return (a%m);
        long long ans = 1;
        while(b > 0){
                if(b%2 == 1) ans = (ans*a)%m;
                a = (a*a)%m;
                b /=2;
        }
        return ans;
}

double log(double a, int b){return log(a)/log(b);}

long long mid(long long a, long long b) {return (a+b)/2;}

class Node{
        public:
            int data;
            Node* right;
            Node* left;
            Node (int data){
                    this->data = data;
                    this->right = NULL;
                    this->left = NULL;
            }
};

Node* insertBinSearch(Node* root, int d){
        Node* carry = new Node(d);
        if(root == NULL) return carry;
        Node* temp = root;
        while(1){
                if(d > temp->data){
                        if(temp->right == NULL) {
                                temp->right = carry;
                                break;
                        }
                        else temp = temp->right;
                }
                else if(d <= temp->data){
                        if(temp->left == NULL) {
                                temp->left = carry;
                                break;
                        }
                        else temp = temp->left;
                }
        }
        return root;
}
void take() {
}

void solve() {
        take();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    fuu(i, t) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

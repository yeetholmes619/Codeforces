#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back


int mex(set<int> v){
        int pos = 0;
        for(auto t: v){
                if(t != pos) return pos;
                pos++;
        }
        return v.size();
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main(int argc, char*argv[]){
        int size = atoi(argv[1]);
        vector<int> v(size);
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
        v[4] = 1;
        v[5] = 0;
        for(int i = 6; i < size; i++){
                if(isPrime(i)) {
                        v[i]  = 0;
                        continue;
                }
                set<int> mexx;
                for(int  j = 2; j <= i/2; j++){
                        if(i%j == 0){
                                mexx.insert(v[i-j]);
                        }
                }
                v[i] = mex(mexx);
        }

        for(int i = 1; i < size; i++){
                //cout<<"The g number of state "<<i<<" is "<<v[i]<<endl;
                if((v[i] == 0) and (i%2 == 0)) cout<<i<<"\n";
        }
}

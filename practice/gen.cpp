#include<bits/stdc++.h>
using namespace std;

int rand(int a,int b){
        return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
        srand(atoi(argv[1]));
        cout<<1<<"\n";
        int n = rand(2,10);
        int k = rand(1,n/2);
        cout<<n<<" "<<k<<"\n";
        for(int i = 2; i <= n; i++){
                int x = rand(1,i-1);
                cout<<x<<" "<<i<<"\n";
        }
}

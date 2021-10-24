#include<bits/stdc++.h>
using namespace std;

int rand(int a,int b){
        return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
        srand(atoi(argv[1]));
        int n = rand(2,20);
        n *= 2;
        cout<<1<<"\n";
        cout<<n<<"\n";
        int k = -1;
        for(int i = 0; i < n; i++){
                cout<<k*rand(10000,1000000)<<" ";
                k *= -1;
        }
        cout<<"\n";
}

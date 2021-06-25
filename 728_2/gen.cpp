#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b){
        return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
        srand(atoi(argv[1]));
        cout<<1<<"\n";
        int n = rand(2,5);
        cout<<n<<endl;
        for(int i = 0; i < n; i++){
                cout<<rand(1,10)<<" ";
        }
        cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;

int rand(int a,int b){
        return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
        srand(atoi(argv[1]));
        cout<<1<<"\n";
        cout<<rand(1e7,1e9);
}

#include<bits/stdc++.h>
using namespace std;
int rand(int a, int b) {return a + rand()%(b-a+1);}
int main(int argc, char* argv[]){
        srand(atoi(argv[1]));
        cout<<1<<endl;
        cout<<rand(1,10)<<" "<<rand(1,10)<<" "<<rand(1,10);
}

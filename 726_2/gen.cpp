#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b){return a + rand()%(b-a+1);}

int main(int trash, char* argv[]){
        srand(atoi(argv[1]));
        string s = "";
        vector<string> v = {"a","b","c","d","e","f","g","h","i","j","k","l"};
        int n = rand(1e3,1e5);
        int k = rand(1,1e3);
        for(int i =  0; i < n; i++){
                s += v[rand(0,11)];
        }
        cout<<n<<" "<<k<<"\n";
        cout<<s;
}

#include<bits/stdc++.h>
using namespace std;
bool query(char a, char b){
        printf("? %c %c\n",a,b);
        fflush(stdout);
        char in;
        cin>>in;
        return in == '<';
}
int n,q;
struct Node {
    char ch;

};
bool operator < (Node const &A,Node const &B) {
    return query(A.ch, B.ch);
}
void insertionSort(vector<Node> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        // Searching the upper bound, i.e., first
        // element greater than *it from beginning
        auto const insertion_point =
            std::upper_bound(vec.begin(), it, *it);

        // Shifting the unsorted part
        std::rotate(insertion_point, it, it + 1);
    }
}
int main(){
  cin>>n>>q;
  vector<Node> s(n);
  for(int i = 0 ; i < n; i++) s[i].ch = (char)('A' + i);
  insertionSort(s);
  printf("! ");
  for(int i =0; i < n; i++){
          printf("%c",s[i].ch);
  }
  printf("\n");
  fflush(stdout);
}
  

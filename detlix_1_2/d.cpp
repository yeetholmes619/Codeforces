#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int andq(int i,int j){
        cout<<"and "<<i<<" "<<j<<endl;
        int ans;
        cin>>ans;
        return ans;
}

int orq(int i,int j){
        cout<<"or "<<i<<" "<<j<<endl;
        int ans;
        cin>>ans;
        return ans;
}
int main(){
        int n,k;
        string s1=  "",s2 = "",s3 = "";
        vector<int> v;
        cin>>n>>k;

        int a12,o12;
        a12 = andq(1,2);
        o12 = orq(1,2);
        for(int  i =0 ; i < 31; i++){
                int it = 1<<i;
                if(a12&it){
                        s1 = '1' + s1;
                        s2 = '1' + s2;
                }
                else if((o12&it) == 0){
                        s1 = '0' + s1;
                        s2 = '0' + s2;
                }
                else{
                        s1 = '2' + s1;
                        s2 = '2' + s2;
                }
        }
        



        int a13,o13;
        a13 = andq(1,3);
        o13 = orq(1,3);
        for(int  i =0 ; i < 31; i++){
                int it = 1<<i;
                if(a13&it){
                        s3 = '1' + s3;
                        s1[30-i] = '1';
                }
                else if((o13&it) == 0){
                        s1[30-i] = '0';
                        s3 = '0' + s3;
                }
                else{
                        if(s1[30-i] == '1'){
                                s3 = '0' + s3;
                        }
                        else if(s1[30-i] == '1'){
                                s3 =  '1' + s3;
                        }
                        else s3 = '2' + s3;
                }
        }



        int a23,o23;
        a23 = andq(2,3);
        o23 = orq(2,3);
        for(int  i =0 ; i < 31; i++){
                int it = 1<<i;
                if(a23&it){
                        s3[30-i] = '1';
                        s2[30-i] = '1';
                }
                else if((o23&it) == 0){
                        s2[30-i] = '0';
                        s3[30-i] = '0';
                }
                else{
                        if(s3[30-i] == '1'){
                                s2[30-i] = '0';
                        }
                        else if(s3[30-i] == '0'){
                                s2[30-i] = '1';
                        }
                        else if(s2[30-i] == '0'){
                                s3[30-i] = '1';
                        }
                        else if(s2[30-i] == '1'){
                                s3[30-i] = '0';
                        }
                }
        }


        for(int  i =0 ;i  < 31; i++){
                int check = 1<<i;
                if(s1[30-i] == '2'){
                        if((o12&check) == 0){
                                s1[30-i] = (s2[30-i] == '1')? '0' : '1';
                        }
                        else{
                                s1[30-i] = (s3[30-i] == '1')?'0':'1';
                        }
                }
        }

        for(int  i =0 ;i  < 31; i++){
                int check = 1<<i;
                if(s3[30-i] == '2'){
                        if((o13&check) == 0){
                                s3[30-i] = (s1[30-i] == '1')? '0' : '1';
                        }
                        else{
                                s3[30-i] = (s2[30-i] == '1')?'0':'1';
                        }
                }
        }

        for(int  i =0 ;i  < 31; i++){
                int check = 1<<i;
                if(s2[30-i] == '2'){
                        if((o23&check) == 0){
                                s2[30-i] = (s3[30-i] == '1')? '0' : '1';
                        }
                        else{
                                s2[30-i] = (s1[30-i] == '1')?'0':'1';
                        }
                }
        }



        int f = 0,s =0, t = 0;
        f = stoi(s1,0,2);
        v.pb(f);
        s = stoi(s2,0,2);
        v.pb(s);
        t = stoi(s3,0,2);
        v.pb(t);

        for(int i = 4; i<= n; i++){
                int anne = andq(1,i);
                int ore = orq(1,i);
                string s = "";
                for(int j = 0; j < 31; j++){
                        int check = 1<<j;
                        if((anne&check) == 1){
                                s = '1' + s;
                        }
                        else if((ore&check) == 0){
                                s = '0' + s;
                        }
                        else{
                                s = ((s1[30-j] == '1') ? '0' : '1') + s;
                        }
                }
                int gg = 0;
                gg = stoi(s,0,2);
                v.pb(gg);
        }

        sort(v.begin(), v.end());
        printf("finish %d\n",v[k-1]);
        fflush(stdout);
}








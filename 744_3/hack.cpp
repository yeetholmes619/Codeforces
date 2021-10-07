
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
 
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()
int main() {
    auto time0 = curtime;
 
	ll t;
	cin>>t;
 
	while(t--) {
	
	int n;
	cin>>n;
	int arr[n];
 
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
 
	std::vector<int> v;
	v.push_back(arr[0]);
 
 
	for (int i = 1; i < n; ++i)
	{
		if(arr[i] < v[0]) {
			v.insert(v.begin(), arr[i]);
		}
		else
			v.push_back(arr[i]);
	}
 
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
	}
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
}

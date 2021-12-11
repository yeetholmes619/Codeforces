// CPP program to find bestArray
#include<bits/stdc++.h>
using namespace std;

// Calculating gcd of two numbers
int gcd(int a, int b){
		if (a == 0)
			return b;
		return gcd(b%a, a);
}

void bestArray(int arr[], int n){
		bool even[n] = {false};
		int ans = 0;

		// calculating gcd and
		// counting the even numbers
		for(int i = 0; i < n; i++){
			ans = gcd(ans, arr[i]);
			if(arr[i] % 2 == 0)
				even[i] = true;
		}

		// check array is already best
		if(ans > 1)
			cout << 0 << endl;
		else{

			// counting the number
			// of operations required.
			ans = 0;
			for(int i = 0; i < n-1; i++){
				if(!even[i]){
					even[i] = true;
					even[i+1] = true;
					if(arr[i+1]%2 != 0){
						ans+=1;
					}
					else
						ans+=2;
				}
			}
			if(!even[n-1]){
				ans+=2;
			}
			cout << ans << endl;
		}
}

// driver code
int main(){
	
		int arr[] = {57, 30, 28, 81, 88, 32, 3, 42, 25};
		int n = 9;
		bestArray(arr, n);

		int arr1[] = {1, 1};
		n = 2;
		bestArray(arr1, n);

		int arr2[] = {6, 2, 4};
		n = 3;
		bestArray(arr2, n);
}

/*This code is contributed by Sagar Shukla.*/


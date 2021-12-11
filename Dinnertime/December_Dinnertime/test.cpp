// C implementation of Naive method to count all
// divisors
#include <bits/stdc++.h>
using namespace std;

// function to count the divisors
int countDivisors(int n)
{
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			// If divisors are equal,
			// count only one
			if (n / i == i)
				cnt++;

			else // Otherwise count both
				cnt = cnt + 2;
		}
	}
	return cnt;
}

/* Driver program to test above function */
int main()
{
        int ans = 0;
        for(int i =0 ; i <= 1000000; i++){
                ans = max(ans,countDivisors(i));
        }
        cout<<ans<<"\n";

return 0;
}


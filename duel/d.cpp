// C++ program to find next identical year
#include<iostream>
using namespace std;

// Function for finding extra days of year
// more than complete weeks
int extraDays(int y)
{
	// If current year is a leap year, then
	// it number of weekdays move ahead by
	// 2 in terms of weekdays.
	if (y%400==0 || y%100!=0 && y%4==0)
		return 2;

	// Else number of weekdays move ahead
	// by 1.
	return 1;
}

// Returns next identical year.
int nextYear(int y)
{
	// Find number of days moved ahead by y
	int days = extraDays(y);

	// Start from next year
	int x = y + 1;

	// Count total number of weekdays
	// moved ahead so far.
	for (int sum=0; ; x++)
	{
		sum = (sum + extraDays(x)) % 7;

		// If sum is divisible by 7 and leap-ness
		// of x is same as y, return x.
		if ( sum==0 && (extraDays(x) == days))
			return x;
	}

	return x;
}

// driver program
int main()
{
        int y;
    cin>>y;
	cout << nextYear(y);
	return 0;
}


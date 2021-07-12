#include <algorithm>
#include <chrono>
#include <complex>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
//using ull = unsigned ll;

void solve() {
    int n;
    cin >> n;

    int p;
    cin >> p;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        cout << ans << ' ';
        int x;
        cin >> x;

        ans = (p ^ x) & p;
        p = x ^ ans;
    }

    cout << ans << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

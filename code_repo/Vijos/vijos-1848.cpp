/*
...
*/

#include <iostream>

using namespace std;

int n, x, ans;

int countNum(int a) {
    int cnt = 0;
    while (a) {
        if (a % 10 == x) {
            ++cnt;
        }
        a /= 10;
    }
    return cnt;
}

void solve() {
   cin >> n >> x;
   for (int i = 1; i <= n; ++i) {
       ans += countNum(i);
   }
   cout << ans;
}

int main() {
	solve();
	return 0;
}
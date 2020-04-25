/*
...
*/

#include <iostream>
#include <unordered_set>

using namespace std;

const int MAXN = 100 + 5;

int n, a[MAXN], ans;
unordered_set<int> book;


void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            book.insert(a[i] + a[j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (book.count(a[i])) {
            ++ans;
        }
    }
    cout << ans;
}

int main() {
	solve();
	return 0;
}
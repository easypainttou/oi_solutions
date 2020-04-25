/*
...
*/

#include <iostream>

using namespace std;

int n;

int callatz(int n) {
    int step = 0;
    while (n != 1) {
        if (n & 1) {
            n = (3 * n + 1) / 2;
        } else {
            n = n / 2;
        }
        ++step;
    }
    return step;
}

void solve() {
    cin >> n;
    cout << callatz(n);
}

int main() {
	solve();
	return 0;
}
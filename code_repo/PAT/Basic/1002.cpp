/*
...
*/

#include <iostream>
#include <string>

using namespace std;

string n, sumStr, dic[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int sum;

void solve() {
    cin >> n;
    for (int i = 0; i < n.length(); ++i) {
        sum += n[i] - '0';
    }
    sumStr = to_string(sum);
    for (int i = 0; i < sumStr.length(); ++i) {
        if (i) cout << " ";
        cout << dic[sumStr[i] - '0'];
    }
}

int main() {
	solve();
	return 0;
}

/*

题意：判断字符串是否为ABABA或ABABCAB的形式

解：大概从数据范围看是暴力。。。

*/

#include <cstdio>
#include <iostream>

typedef long long LL;

using namespace std;

const int MAX_N = 55 + 5;
const int INF = 0x3f3f3f3f;

int T, n;
string oriS, s;

bool isType1() {
	int u = (n - 2) / 3;
	for (int i = 1; i <= u; i++) {
		int num = n - 3 * i;
		if (num & 1) continue;
		num >>= 1;
		string a1 = s.substr(0, i), b1 = s.substr(i, num), a2 = s.substr(i + num, i), b2 = s.substr(2 * i + num, num), a3 = s.substr(2 * i + 2 * num, i);
		if(a1 == a2 && a2 == a3 && b1 == b2 && a1 != b1) {
			return 1;
		}
	}
	return 0;
}

bool isType2() {
	int u1 = (n - 4) / 3;
	for (int i = 1; i <= u1; i++) {
		int u2 = (n - 3 * i -1) / 3;
		for (int j = 1; j <= u2; j++) {
			int num = n - 3 * i - 3 * j;
			string a1 = s.substr(0, i), b1 = s.substr(i, j), a2 = s.substr(i + j, i), b2 = s.substr(2 * i + j, j), c = s.substr(2 * i + 2 * j, num), a3 = s.substr(2 * i + 2 * j + num, i), b3 = s.substr(3 * i + 2 * j + num, j);
			if (a1 == a2 && a2 == a3 && b1 == b2 && b2 == b3 && a1 != b1 && b1 != c && a1 != c) {
				return 1;
			}
		}
	}
	return 0;
}

inline bool isLetter(char ch) {
	return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <='z';
}

void solve() {
	cin >> T;
	while (T--) {
		cin >> oriS;
		s = "";
		n = oriS.size();
		for (int i = 0; i < n; i++) {
			if (isLetter(oriS[i]))s += oriS[i];
		}
		n = s.size();
		if (isType1() || isType2()) puts("Yes");
		else puts("No");
	}
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
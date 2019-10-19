/*

题意：最长回文子串，加上H[1] <= H[2] <= H[3] .... <= H[mid]的限制

解：使用manacher，只需在扩展r[i]时加上条件h2[i - r[i]] <= h2[i - r[i] + 2]

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

int T, n1, n2, h1[MAX_N], h2[MAX_N << 1], r[MAX_N << 1];

int read() {
	int res = 0;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) ;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res;
}

void build() {
	int tot = 0;
	h2[++tot] = 1;
	for (int i = 1; i <= n1; ++i) h2[++tot] = 2, h2[++tot] = h1[i];
	h2[++tot] = 2, h2[++tot] = 3;
	n2 = tot;
}

int manacher() {
	build();
	int res = 0, maxR = 0, pos = 0;
	for (int i = 2; i < n2; ++i) {
		r[i] = i < maxR ? min(r[(pos << 1) - i], maxR - i + 1) : 1;
		while (h2[i - r[i]] == h2[i + r[i]] && h2[i - r[i]] <= h2[i - r[i] + 2]) ++r[i];
		if (i + r[i] - 1 > maxR) {
			maxR = i + r[i] - 1;
			pos = i;
		}
		res = max(res, r[i] - 1);
	}
	return res;
}

void solve() {
	T = read();
	while (T--) {
		n1 = read();
		for (int i = 1; i <= n1; ++i) h1[i] = read();
		printf("%d\n", manacher());
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
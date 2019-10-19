/*

题意：n个数的序列a0,...,an-1，对于序列ak,...,an-1,a0,...,ak-1,(0<=k<=n-1)，求满足序列所有前缀和>=0的序列的个数

解：先把ai复制一遍放后面，对a求前缀和，然后维护一个单调递增的单调队列，a[q[head]] >= a[i - n]，则++ans

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 5;

int n, a[MAX_N << 1], q[MAX_N << 1], L, R, ans;

int read() {
	int f = 1, res = 0;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

void solve() {
	while (1) {
		n = read();
		if (!n) break;
		for (int i = 1; i <= n; ++i) a[i] = read(), a[i] += a[i - 1];
		for (int i = n + 1; i < n << 1; ++i) {
			a[i] = a[i - n] + a[n];
		}
		L = 1, R = 0, ans = 0;
		for (int i = 1; i < n << 1; ++i) {
			while (L <= R && a[q[R]] >= a[i]) --R;
			q[++R] = i;
			while (L <= R && q[L] <= i - n) ++L;
			if (i >= n && a[q[L]] >= a[i - n]) ++ans;
		}
		printf("%d\n", ans);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
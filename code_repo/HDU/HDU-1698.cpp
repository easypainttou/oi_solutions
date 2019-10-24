/*

题意：初始的时候，整个序列都是1，接下来，每次输入l，r，x。表示将l到r之间修改为x且x只会是1、2、3，最后问你序列总和。

解：
区间修改，赋值
区间查询，总和
线段树，需要懒惰标记
qwq

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)
#define lson (rt << 1)
#define rson (rt << 1 | 1)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 4e4 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int val[MAX_N << 2], lazy[MAX_N << 2];

int T, n, q;

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline void pushUp(int rt) {
	val[rt] = val[lson] + val[rson];
}

inline void pushDown(int rt, int L, int R) {
	if (lazy[rt]) {
		int mid = L + R >> 1;
		lazy[lson] = lazy[rson] = lazy[rt];
		val[lson] = lazy[rt] * (mid - L + 1);
		val[rson] = lazy[rt] * (R - mid);
		lazy[rt] = 0;
	}
}

void build(int rt, int L, int R) {
	lazy[rt] = 0;
	if (L == R) {
		val[rt] = 1;
		return;
	}
	int mid = L + R >> 1;
	build(lson, L, mid), build(rson, mid + 1, R);
	pushUp(rt);
}

void update(int rt, int L, int R, int s, int t, int k) {
	if (s <= L && R <= t) {
		lazy[rt] = k;
		val[rt] = (R - L + 1) * k;
		return;
	}
	pushDown(rt, L, R);
	int mid = L + R >> 1;
	if (s <= mid) update(lson, L, mid, s, t, k);
	if (t > mid) update(rson, mid + 1, R, s, t, k);
	pushUp(rt);
}

void solve() {
	T = read();
	for (int kase = 1; kase <= T; ++kase) {
		n = read(), q = read();
		build(1, 1, n);
		while (q--) {
			int x = read(), y = read(), z = read();
			update(1, 1, n, x, y, z);
		}
		printf("Case %d: The total value of the hook is %d.\n", kase, val[1]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
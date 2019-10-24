/*

题意：长度为n的序列a
2种操作
0 l r 代表把区间[l，r]的每个数都开根号（向下取整）
1 l r 输出区间[l，r]里所有数的和是多少

解：
线段树
2^63最多7次到1，对区间内单点修改，对每个点开根号，然而单点修改会T，所以优化
考虑到若某个值已经<=1，则不需要开根号，所以区间和<=区间长度则不考虑这个区间
然后区间查询，求和

*/

#include <cstdio>
#include <cstring>
#include <cmath>
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
LL sum[MAX_N << 2], a[MAX_N];

int n, m;

LL read() {
	LL res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline void pushUp(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}

void build(int rt, int L, int R) {
	if (L == R) {
		sum[rt] = a[L];
		return;
	}
	int mid = L + R >> 1;
	build(lson, L, mid), build(rson, mid + 1, R);
	pushUp(rt);
}

void update(int rt, int L, int R, int s, int t) {
	if (L == R) {
		sum[rt] = (LL)(sqrt(sum[rt]));
		return;
	}
	int mid = L + R >> 1;
	if (s <= mid && sum[lson] > mid - L + 1) update(lson, L, mid, s, t);
	if (t > mid && sum[rson] > R - mid) update(rson, mid + 1, R, s, t);
	pushUp(rt);
}

LL query(int rt, int L, int R, int s, int t) {
	if (s <= L && R <= t) {
		return sum[rt];
	}
	int mid = L + R >> 1;
	LL res = 0;
	if (s <= mid) res += query(lson, L, mid, s, t);
	if (t > mid) res += query(rson, mid + 1, R, s, t);
	return res;
}

void solve() {
	int kase = 0;
	while (~scanf("%d", &n)) {
		printf("Case #%d:\n", ++kase);
		inc(i, 1, n) a[i] = read();
		build(1, 1, n);
		m = read();
		while (m--) {
			int op = read(), x = read(), y = read();
			if (x > y) swap(x, y);
			if (op) {
				printf("%lld\n", query(1, 1, n, x, y));
			} else {
				update(1, 1, n, x, y);
			}
		}
		puts("");
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
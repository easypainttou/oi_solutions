/*

题意：一个序列，处理如下两种询问。
"C a b c"表示给[a, b]区间中的值全部增加c (-10000 ≤ c ≤ 10000)。
"Q a b" 询问[a, b]区间中所有值的和。

解：
区间修改，加法
区间查询，求和
线段树，需要懒惰标记

*/

#include <cstdio>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)
#define lson (rt << 1)
#define rson (rt << 1 | 1)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 6e6 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
LL sum[MAX_N << 2], lazy[MAX_N << 2];

int n, q, a[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline void pushUp(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}

inline void pushDown(int rt, int L, int R) {
	if (lazy[rt]) {
		int mid = L + R >> 1;
		lazy[lson] += lazy[rt], lazy[rson] += lazy[rt];
		sum[lson] += lazy[rt] * (mid - L + 1), sum[rson] += lazy[rt] * (R - mid);
		lazy[rt] = 0;
	}
}

void build(int rt, int L, int R) {
	sum[rt] = lazy[rt] = 0;
	if (L == R) {
		sum[rt] = a[L];
		return;
	}
	int mid = L + R >> 1;
	build(lson, L, mid), build(rson, mid + 1, R);
	pushUp(rt);
}

void update(int rt, int L, int R, int s, int t, int k) {
	if (s <= L && R <= t) {
		lazy[rt] += k;
		sum[rt] += k * (R - L + 1);
		return;
	}
	pushDown(rt, L, R);
	int mid = R + L >> 1;
	if (s <= mid) update(lson, L, mid, s, t, k);
	if (t > mid) update(rson, mid + 1, R, s, t, k);
	pushUp(rt);
}

LL query(int rt, int L, int R, int s, int t) {
	if (s <= L && R <= t) {
		return sum[rt];
	}
	pushDown(rt, L, R);
	int mid = R + L >> 1;
	LL res = 0;
	if (s <= mid) res += query(lson, L, mid, s, t);
	if (t > mid) res += query(rson, mid + 1, R, s, t);
	return res;
}


void solve() {
	n = read(), q = read();
	inc(i, 1, n) a[i] = read();
	build(1, 1, n);
	inc(i, 1, q) {
		char s[2];
		int x, y, z;
		scanf("%s", s);
		x = read(), y = read();
		if (s[0] == 'C') {
			z = read();
			update(1, 1, n, x, y, z);
		} else {
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
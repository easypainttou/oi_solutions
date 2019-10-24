/*

题意：n（n<=10000) 个人依次贴海报,给出每张海报所贴的范围li，ri（1<=li<=ri<=10000000) 。求出最后还能看见多少张海报。

解：线段树染色
离散化若两相邻坐标之间差值大于1，需要再在中间加一个点，说明中间有空隙
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

const int MAX_N = 1e4 + 5;
const int MAX_M = 4e4 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int val[MAX_M << 2];

int T, n, li[MAX_N], ri[MAX_N], b[MAX_M], len, ans;
bool vis[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline int getId(int k) {
	return lower_bound(b + 1, b + len + 1, k) - b;
}

inline void pushUp(int rt) {
	if (val[lson] == val[rson]) {
		val[rt] = val[lson];
	} else {
		val[rt] = -1;
	}
}

inline void pushDown(int rt) {
	if (val[rt] != -1) {
		val[lson] = val[rt], val[rson] = val[rt];
	}
}

void update(int rt, int L, int R, int s, int t, int k) {
	if (s <= L && R <= t) {
		val[rt] = k;
		return;
	}
	pushDown(rt);
	int mid = L + R >> 1;
	if (s <= mid) update(lson, L, mid, s, t, k);
	if (t > mid) update(rson, mid + 1, R, s, t, k);
	pushUp(rt);
}

void query(int rt, int L, int R) {
	if (val[rt] != -1) {
		if (!vis[val[rt]]) vis[val[rt]] = 1, ++ans;
		return;
	}
	if (L == R) return;
	int mid = L + R >> 1;
	query(lson, L, mid);
	query(rson, mid + 1, R);
}

inline void init() {
	ans = 0;
	memset(vis, 0, sizeof(vis));
}

void solve() {
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		inc(i, 1, n) {
			scanf("%d%d", li + i, ri + i);
			b[(i << 1) - 1] = li[i];
			b[i << 1] = ri[i];
		}
		sort(b + 1, b + (n << 1) + 1);
		len = unique(b + 1, b + (n << 1) + 1) - b - 1;
		int tmp = len;
		for (int i = 1; i < tmp; ++i) {
			if (b[i] + 1 != b[i + 1]) b[++len] = b[i] + 1;
		}
		sort(b + 1, b + len + 1);
		memset(val, 0xff, sizeof(val));
		for (int i = 1; i <= n; ++i) {
			update(1, 1, len, getId(li[i]), getId(ri[i]), i);
		}
		query(1, 1, len);
		printf("%d\n", ans);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
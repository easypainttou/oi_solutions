/*

静态区间第k小
主席树板子
qwq

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int sum[MAX_N << 5], lson[MAX_N << 5], rson[MAX_N << 5];

int n, m, a[MAX_N], b[MAX_N], head[MAX_N], cnt, len;

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline int getId(const int & k) {
	return lower_bound(b + 1, b + len + 1, k) - b;
}

int build(int L, int R) {
	int rt = ++cnt;
	sum[rt] = lson[rt] = rson[rt] = 0;
	if (L == R) return rt;
	int mid = (L + R) >> 1;
	lson[rt] = build(L, mid);
	rson[rt] = build(mid + 1, R);
	return rt;
}

int update(int p, int L, int R, int k) {
	int rt = ++cnt;
	lson[rt] = lson[p];
	rson[rt] = rson[p];
	sum[rt] = sum[p] + 1;
	if (L == R) return rt;
	int mid = (L + R) >> 1;
	if (k <= mid) lson[rt] = update(lson[p], L, mid, k);
	else rson[rt] = update(rson[p], mid + 1, R, k);
	return rt;
}

int query(int u, int v, int L, int R, int k) {
	if (L == R) return L;
	int mid = (L + R) >> 1, x = sum[lson[v]] - sum[lson[u]];
	if (k <= x) return query(lson[u], lson[v], L, mid, k);
	else return query(rson[u], rson[v], mid + 1, R, k - x);
}

void solve() {
	n = read(), m = read();
	inc(i, 1, n) a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	head[0] = build(1, len);
	inc(i, 1, n) head[i] = update(head[i - 1], 1, len, getId(a[i]));
	inc(i, 1, m) {
		int L = read(), R = read(), k = read();
		printf("%d\n", b[query(head[L - 1], head[R], 1, len, k)]);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
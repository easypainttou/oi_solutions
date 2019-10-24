/*

题意：给一个数列，每次询问一个区间内有没有一个数出现次数超过一半

解：主席树板子qwq

*/

#include <cstdio>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

typedef long long LL;

const int MAX_N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int sum[MAX_N << 5], lson[MAX_N << 5], rson[MAX_N << 5];

int n, m, a, head[MAX_N], cnt;

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
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
	int mid = (L + R) >> 1;
	if (k < 2 * (sum[lson[v]] - sum[lson[u]])) return query(lson[u], lson[v], L, mid, k);
	if (k < 2 * (sum[rson[v]] - sum[rson[u]])) return query(rson[u], rson[v], mid + 1, R, k);
	return 0;
}

void solve() {
	n = read(), m = read();
	head[0] = build(1, n);
	inc(i, 1, n) a = read(), head[i] = update(head[i - 1], 1, n, a);
	inc(i, 1, m) {
		int L = read(), R = read();
		printf("%d\n", query(head[L - 1], head[R], 1, n, R - L + 1));
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
/*

题意：给定一棵N个节点的树，每个点有一个权值，对于M个询问(u,v,k)，你需要回答u xor lastans和v这两个节点间第K小的点权。其中lastans是上一个询问的答案，初始为0，即第一个询问的u是明文。

解：dfs遍历树，到u的时候建立一个从根到u前缀的主席树s[u]，包含u到v这个路径上的信息的主席树是s[u]+s[v]-s[lca(u,v)]-s[fa[lca(u,v)][0]]

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
const int MAX_M = MAX_N << 2;
const LL MOD = 10007;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

struct Edge {
	int v, next;
} es[MAX_N << 1];

int n, m, tot, head[MAX_N], a[MAX_N], b[MAX_N], len, dep[MAX_N], fa[MAX_N][20];

//seg
int sum[MAX_N << 5], T[MAX_N], cnt, ls[MAX_N << 5], rs[MAX_N << 5];

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

inline void addEdge(int u, int v) {
	es[++tot].v = v, es[tot].next = head[u], head[u] = tot;
}

void build (int & rt, int L, int R) {
	rt = ++cnt;
	sum[rt] = 0;
	if (L == R) return;
	int mid = L + R >> 1;
	build(ls[rt], L, mid), build(rs[rt], mid + 1, R);
}

void insert(int & rt, int & pre, int L, int R, int k) {
	rt = ++cnt;
	ls[rt] = ls[pre];
	rs[rt] = rs[pre];
	sum[rt] = sum[pre] + 1;
	if (L == R) return;
	int mid = L + R >> 1;
	if (k <= mid) insert(ls[rt], ls[pre], L, mid, k);
	else insert(rs[rt], rs[pre], mid + 1, R, k);
	sum[rt] = sum[ls[rt]] + sum[rs[rt]];
}

int query(int & u, int & v, int & p, int & pp, int L, int R, int k) {
	if (L == R) return L;
	int mid = L + R >> 1, tmp = sum[ls[u]] + sum[ls[v]] - sum[ls[p]] - sum[ls[pp]];
	if (k <= tmp) return query(ls[u], ls[v], ls[p], ls[pp], L, mid, k);
	else return query(rs[u], rs[v], rs[p], rs[pp], mid + 1, R, k - tmp);
}

void dfs(int u, int f) {
	insert(T[u], T[f], 1, len, getId(a[u]));
	dep[u] = dep[f] + 1;
	fa[u][0] = f;
	inc(i, 1, 15) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = es[i].next) {
		if (f == es[i].v) continue;
		dfs(es[i].v, u);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 15; i >= 0; --i) if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 15; i >= 0; --i) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void solve() {
	n = read(), m = read();
	inc(i, 1, n) a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	inc(i, 1, n - 1) {
		int u = read(), v = read();
		addEdge(u, v), addEdge(v, u);
	}
	build(T[0], 1, len);
	dfs(1, 0);
	int lastans = 0;
	inc(i, 1, m) {
		int u = read() ^ lastans, v = read(), k = read(), p = lca(u, v);
		lastans = b[query(T[u], T[v], T[p], T[fa[p][0]], 1, len, k)];
		printf("%d\n", lastans);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
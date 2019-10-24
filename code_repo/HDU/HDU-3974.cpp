/*

题意：有一家公司有N个员工(从1到N)，公司里每个员工都有一个直接的老板(除了整个公司的领导)。如果你是某人的直接老板，那个人就是你的下属，他的所有下属也都是你的下属。如果你是没有人的老板，那么你就没有下属，没有直接老板的员工就是整个公司的领导，也就是说N个员工构成了一棵树。公司通常把一些任务分配给一些员工来完成，当一项任务分配给某个人时，他/她会把它分配给他/她的所有下属，换句话说，这个人和他/她的所有下属在同一时间接受了一项任务。此外，每当员工收到一个任务，他/她将停止当前任务(如果他/她有)，并开始新的任务。在公司将某些任务分配给某个员工后，编写一个程序来帮助找出某个员工当前的任务。
“Cx”表示对员工x的当前任务的查询，“Tx y”表示公司将任务y分配给员工x

解：记录结点的dfs序，子树上的结点的dfs序是连续的，所以可以把子树放到线段树上，然后是线段树染色qwq

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

const int MAX_N = 5e4 + 5;
const int MAX_M = 4e4 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int val[MAX_N << 2];

struct Edge {
	int v, next;
} es[MAX_N << 1];

int T, n, m, boss, tot, ind[MAX_N], head[MAX_N], cnt, idl[MAX_N], idr[MAX_N];

LL read() {
	LL res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline void addEdge(int u, int v) {
	es[++tot].v = v, es[tot].next = head[u], head[u] = tot;
}

inline void addPair(int u, int v) {
	addEdge(u, v), addEdge(v, u);
}

void dfs(int u, int f) {
	idl[u] = ++cnt;
	for (int i = head[u]; i; i = es[i].next) {
		if (es[i].v == f) continue;
		dfs(es[i].v, u);
	}
	idr[u] = cnt;
}

inline void pushUp(int rt) {
	val[rt] = val[lson] == val[rson] ? val[lson] : -1;
}

inline void pushDown(int rt) {
	if (val[rt] != -1) {
		val[lson] = val[rson] = val[rt];
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

int query(int rt, int L, int R, int pos) {
	if (val[rt] != -1 || L == R) return val[rt];
	//pushDown(rt);
	int mid = L + R >> 1;
	if (pos <= mid) return query(lson, L, mid, pos);
	else return query(rson, mid + 1, R, pos);
}


inline void init() {
	cnt = tot = 0;
	memset(head, 0, sizeof(head));
	memset(val, 0, sizeof(val));
	memset(ind, 0, sizeof(ind));
}

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		init();
		printf("Case #%d:\n", kase);
		scanf("%d", &n);
		inc(i, 1, n - 1) {
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(v, u);
			++ind[u];
		}
		for (int i = 1; i <= n; ++i) if (!ind[i]) boss = i;
		dfs(boss, 0); //这是有根树，wa在这里qwq
		scanf("%d", &m);
		inc(i, 1, m) {
			char s[2];
			int x, y;
			scanf("%s%d", s, &x);
			if (s[0] == 'C') {
				printf("%d\n", query(1, 1, n, idl[x]) - 1);
			} else {
				scanf("%d", &y); ++y;
				update(1, 1, n, idl[x], idr[x], y);
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
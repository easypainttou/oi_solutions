/*

题意：n个点的树，每条边有权值，结点x和y之间的路径长度为路径上各边的权值和，求长度不超过k的路径数

解：点分治 板子题。。。
选择树的重心rt
从rt出发求各点深度dep
函数calc(rt)：dep放入数组d，从小到大排序。指针L从前、R从后开始，若d[L] + d[R] <= k，res += R - L, L++，否则R--
答案增加calc(rt)，删除rt，对子树执行以上步骤，执行之前需要去重，也就是减去calc(v)，v是rt的子节点
qwq

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 10;
const int MAX_M = 3e4 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

struct Edge {
	int v, w, next;
} es[MAX_N << 1];
int n, k, tot, head[MAX_N], rt, mn, sz[MAX_N], sn, ans, dep[MAX_N], d[MAX_N], cnt;
bool vis[MAX_N];

inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
}

void getRoot(int u, int fa) {
	sz[u] = 1;
	int mx = 0;
	for (int i = head[u]; i; i = es[i].next) {
		int v = es[i].v;
		if (vis[v] || v == fa) continue;
		getRoot(v, u);
		sz[u] += sz[v];
		mx = max(mx, sz[v]);
	}
	mx = max(mx, sn - sz[u]);
	if (mn > mx) {
		mn = mx;
		rt = u;
	}
}

void getDep(int u, int fa) {
	d[++cnt] = dep[u];
	for (int i = head[u]; i; i = es[i].next) {
		int v = es[i].v;
		if (vis[v] || v == fa) continue;
		dep[v] = dep[u] + es[i].w;
		getDep(v, u);
	}
}

int calc(int u) {
	cnt = 0, getDep(u, 0);
	sort(d + 1, d + cnt + 1);
	int L = 1, R = cnt, res = 0;
	while (L < R) {
		if (d[L] + d[R] <= k) res += R - L, L++;
		else R--;
	}
	return res;
}

void dfs(int u) {
	vis[u] = 1;
	dep[u] = 0;
	ans += calc(u);
	for (int i = head[u]; i; i = es[i].next) {
		int v = es[i].v;
		if (vis[v]) continue;
		ans -= calc(v);
		mn = INF, sn = sz[v], getRoot(v, u);
		dfs(rt);
	}
}

inline void init() {
	tot = ans = 0;
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
}

void solve() {
	while (1){
		scanf("%d%d", &n, &k);
		if (!n && !k) break;
		init();
		inc(i, 1, n - 1) {
			int u, v, l;
			scanf("%d%d%d", &u, &v, &l);
			addEdge(u, v, l);
			addEdge(v, u, l);
		}
		mn = INF, sn = n, getRoot(1, 0), dfs(rt);
		printf("%d\n", ans);
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}
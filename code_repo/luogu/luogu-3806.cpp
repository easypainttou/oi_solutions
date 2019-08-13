/*

题意：给定一棵有n个点的树。询问树上距离为k的点对是否存在。

解：点分治 板子题。预处理，calc为统计距离，其它都是板子。。然后对于一个询问直接输出

*/

#include <cstdio>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e4 + 10;
const int MAX_M = 1e7 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

struct Edge {
	int v, w, next;
} es[MAX_N << 1];
int n, m, tot, head[MAX_N], cnt[MAX_M], rt, mn, sz[MAX_N], sn, dep[MAX_N], d[MAX_N], dCnt;
bool vis[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (f == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}


inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
}

void dfsRt(int u, int fa) {
	int mx = 0;
	sz[u] = 1;
	for (int i = head[u]; i; i = es[i].next) {
		int & v = es[i].v;
		if (vis[v] || v == fa) continue;
		dfsRt(v, u);
		sz[u] += sz[v];
		mx = max(mx, sz[v]);
	}
	mx = max(mx, sn - sz[u]);
	if (mn > mx) {
		mn = mx;
		rt = u;
	}
}

void dfsDep(int u, int fa) {
	d[++dCnt] = dep[u];
	for (int i = head[u]; i; i = es[i].next) {
		int & v = es[i].v;
		if (vis[v] || v == fa) continue;
		dep[v] = dep[u] + es[i].w;
		dfsDep(v, u);
	}
}

void calc(int u, int len, bool flag) {
	dCnt = 0, dep[u] = len, dfsDep(u, 0);
	//以下是O(n^2)的。还有一个O(nm)的，需要把询问记录下来，使用数组b记录结点属于哪个子树（这个改一下dfsDep就行），对d数组排序，然后对于每一个询问，指针L从前，R从后，线性地扫描，找到满足b[i]!=b[j]、d[i]+d[j]==k的
	inc (i, 1, dCnt) {
		inc(j, i + 1, dCnt) {
			if (flag && d[i] + d[j] <= 1e7) cnt[d[i] + d[j]]++;
			if (!flag && d[i] + d[j] <= 1e7) cnt[d[i] + d[j]]--;
			
		}
	}
}

void dfsAns(int u, int fa) {
	vis[u] = 1;
	calc(u, 0, 1);
	for (int i = head[u]; i; i = es[i].next) {
		int & v = es[i].v;
		if (vis[v] || v == fa) continue;
		calc(v, dep[v], 0), sn = sz[v], mn = INF, dfsRt(v, u), dfsAns(rt, 0);
	}
}

void solve() {
	n = read(), m = read();
	inc(i, 1, n - 1) {
		int a = read(), b = read(), c = read();
		addEdge(a, b, c);
		addEdge(b, a, c);
	}
	sn = n, mn = INF, dfsRt(1, 0), dfsAns(rt, 0);
	inc(i, 1, m) {
		int k;
		k = read();
		printf("%s\n", cnt[k] ? "AYE" : "NAY");
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}
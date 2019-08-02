/*

题意：n个地点，m条边。一开始每个地点ai个人，某个地点的人可以不走或走到相邻的地点，判断能否使每个地点变为bi人，并输出i转移到j的人数aij

解：把n个地点拆成2个点i和i+n(2<=i<=n+1)，源点为1，汇点为2n+2。1向2~n+1连容量为ai的边，n+2~2n+1向2n+2连容量bi的边，如果i和j相邻，i+1向j+n+1连容量无穷的边，j+1向i+n+1连容量无穷的边，然后跑最大流

数据范围开小了返回的是wa，看了很久qwq

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 200 + 5;
const int MAX_M = 1400 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w, next;
} es[MAX_M];
int n, m, a[MAX_N], b[MAX_N], tot = 1, head[MAX_N], s, t, dep[MAX_N], cur[MAX_N], sum1, sum2, g[MAX_N][MAX_N];
queue<int> Q;

inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
	es[++tot].v = u, es[tot].w = 0, es[tot].next = head[v], head[v] = tot;
}

bool BFS() {
	memcpy(cur, head, sizeof(cur));
	memset(dep, 0xff, sizeof(dep));
	while (Q.size()) Q.pop();
	dep[s] = 0;
	Q.push(s);
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		for (int i = head[u]; i; i = es[i].next) {
			int v = es[i].v, w = es[i].w;
			if (dep[v] == -1 && w > 0) {
				dep[v] = dep[u] + 1;
				Q.push(v);
			}
		}
	}
	return dep[t] != -1;
}

int DFS(int u, int a) {
	if (u == t || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[u]; i; i = es[i].next) {
		int v = es[i].v, w = es[i].w;
		if (dep[u] + 1 == dep[v] && (f = DFS(v, min(w, a))) > 0) {
			es[i].w -= f;
			es[i ^ 1].w += f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int dinic() {
	int flow = 0;
	while (BFS()) {
		flow += DFS(s, INF);
	}
	return flow;
}

void solve() {
	scanf("%d%d", &n, &m);
	s = 1, t = (n << 1) + 2;
	for (int i = 1; i <= n; i++) scanf("%d", a + i), addEdge(s, i + 1, a[i]), sum1 += a[i];
	for (int i = 1; i <= n; i++) scanf("%d", b + i), addEdge(i + n + 1, t, b[i]), sum2 += b[i];
	if (sum1 != sum2) {
		puts("NO");
		return;
	}
	for (int i = 1; i <= m; i++) {
		int p, q;
		scanf("%d%d", &p, &q);
		addEdge(p + 1, q + n + 1, INF);
		addEdge(q + 1, p + n + 1, INF);
	}
	for (int i = 1; i <= n; i++) {
		addEdge(i + 1, i + n + 1, INF);
	}
	if (dinic() == sum1) {
		puts("YES");
		for (int i = 2; i <= n + 1; i++) {
			for (int j = head[i]; j; j = es[j].next) {
				int v = es[j].v;
				if (v >= n + 2) g[i - 1][v - n - 1] = es[j ^ 1].w;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", g[i][j]);
			} puts("");
		}
	} else {
		puts("NO");
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
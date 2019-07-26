/*

「网络流 24 题」搭配飞行员

解：二分图最大匹配，这里使用dinic，s为超级源点，t为超级汇点，s到1~m连边，m+1~n到t连边，a和b连边，所有边容量为1

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = 100 + 10;
const int MAX_E = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct edge {
	int v, w, next;
} es[MAX_E];
int n, m, s, t, a, b, tot, head[MAX_V], dep[MAX_V], cur[MAX_V];
bool vis[MAX_V];
queue<int> q;

inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
}

inline void addPair(int u, int v, int w) {
	addEdge(u, v, w);
	addEdge(v, u, 0);
}

bool bfs() {
	memcpy(cur, head, sizeof(head));
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) q.pop();
	vis[s] = 1;
	dep[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = es[i].next) {
			int v = es[i].v, w = es[i].w;
			if (!vis[v] && w > 0) {
				vis[v] = 1;
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return vis[t];
}

int dfs(int u, int a) {
	if (u == t || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[u]; i; i = es[i].next) {
		if (dep[u] + 1 == dep[es[i].v] && (f = dfs(es[i].v, min(es[i].w, a))) > 0) {
			es[i].w -= f;
			es[i^1].w +=f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int dinic() {
	int flow = 0;
	while (bfs()) {
		flow += dfs(s, INF);
	}
	return flow;
}

void solve() {
	scanf("%d%d", &n, &m);
	tot = 1, s = 1, t = n + 2;
	while (~scanf("%d%d", &a, &b)) {
		a++, b++;
		addPair(a, b, 1);
	}
	for (int i = 1; i <= m; i++) addPair(s, i+1, 1);
	for (int i = m + 1; i <= n; i++) addPair(i+1, t, 1);
	printf("%d", dinic());
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
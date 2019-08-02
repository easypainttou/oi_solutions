/*

最小费用最大流板子题
MCMF算法

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)

using namespace std;

const int MAX_N = 5e3 + 5;
const int MAX_M = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int u, v, f, c, next;
} es[MAX_M];
int n, m, tot = 1, head[MAX_N], s, t, dis[MAX_N], flow[MAX_N], pre[MAX_N], maxF, minC;
bool vis[MAX_N];
queue<int> q;

inline void addEdge(int u, int v, int f, int c) {
	es[++tot].u = u, es[tot].v = v, es[tot].f = f, es[tot].c = c, es[tot].next = head[u], head[u] = tot;
}

inline void addPair(int u, int v, int f, int c) {
	addEdge(u, v, f, c);
	addEdge(v, u, 0, -c);
}

bool SPFA() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while (q.size()) q.pop();
	dis[s] = 0;
	flow[s] = INF;
	flow[t] = 0;
	vis[s] = 1;
	q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = es[i].next) {
			int & v = es[i].v, & f = es[i].f, & c = es[i].c;
			if (f > 0 && dis[v] > dis[u] + c) {
				flow[v] = min(f, flow[u]);
				dis[v] = dis[u] + c;
				pre[v] = i;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return flow[t];
}

int MCMF() {
	while (SPFA()) {
		int u = t;
		maxF += flow[t];
		minC += dis[t] * flow[t];
		while (u != s) { 
			es[pre[u]].f -= flow[t];
			es[pre[u]^1].f += flow[t];
			u = es[pre[u]].u;
		}
	}
}

void solve() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	inc(i, 1, m) {
		int u, v, w, f;
		scanf("%d%d%d%d", &u, &v, &w, &f);
		addPair(u, v, w, f);
	}
	MCMF();
	printf("%d %d", maxF, minC);
}

int main() {
	solve();
	return 0;
}
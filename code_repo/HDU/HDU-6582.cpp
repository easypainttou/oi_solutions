/*

题意:在图上去掉一些边，使原来的最短路不存在，求去掉的边的最小权值和

解：先求1到n的最短路，用所有在最短路上的边（满足e.w==dis[e.v]-dis[e.u]）以边权为容量建立一个新的图，求最小割
使用链式前向星一直T，改成邻接表就AC了？qwq

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_V = 1e4 + 10;
const int MAX_E = 1e4 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
	LL u, v, w;
	Edge(LL u = 0, LL v = 0, LL w = 0): u(u), v(v), w(w) {}
};
vector<Edge> g[MAX_V], es, es1;
vector<LL> g1[MAX_V];
LL T, n, m, dis[MAX_V], s, t, dep[MAX_V], cur[MAX_V];
bool vis[MAX_V];
priority_queue< pair<LL, LL> > Q;
queue<LL> Q1;

void dijkstra() {
	while (Q.size()) Q.pop();
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	Q.push(make_pair(0, 1));
	dis[1] = 0;
	while (Q.size()) {
		LL u = Q.top().second; Q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			Edge& e = g[u][i];
			if (!vis[e.v] && dis[e.v] > dis[u] + e.w) {
				dis[e.v] = dis[u] + e.w;
				Q.push(make_pair(-dis[e.v], e.v));
			}
		} 
	}
}

void getNewG() {
	for (int i = 0; i < es.size(); i++) {
		Edge& e = es[i];
		if (e.w == dis[e.v] - dis[e.u]) {
			es1.push_back(Edge(e.u, e.v, e.w));
			es1.push_back(Edge(e.v, e.u, 0));
			int tot = es1.size();
			g1[e.u].push_back(tot - 2);
			g1[e.v].push_back(tot - 1);
		}
	}
}

bool BFS() {
	memset(cur, 0, sizeof(cur));
	while (Q1.size()) Q1.pop();
	memset(dep, 0xff, sizeof(dep));
	Q1.push(s);
	dep[s] = 0;
	while (Q1.size()) {
		int u = Q1.front(); Q1.pop();
		for (int i = 0; i < g1[u].size(); i++) {
			Edge & e = es1[g1[u][i]];
			if (dep[e.v] == -1 && e.w > 0) {
				dep[e.v] = dep[u] + 1;
				Q1.push(e.v);
			}
		}
	}
	return dep[t] != -1;
}

LL DFS(LL u, LL a) {
	if (a == 0 || u == t) return a;
	LL flow = 0, f;
	for (LL & i = cur[u]; i < g1[u].size(); i++) {
		LL id = g1[u][i];
		Edge & e = es1[id]; 
		if (dep[e.v] == dep[u] + 1 && (f = DFS(e.v, min(a, e.w)))) {
			es1[id].w -= f;
			es1[id ^ 1].w += f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

LL dinic() {
	LL flow = 0;
	while (BFS()) {
		flow += DFS(s, INF);
	}
	return flow;
}

inline void init() {
	for (int i = 0 ; i < MAX_V; i++) g[i].clear();
	for (int i = 0 ; i < MAX_V; i++) g1[i].clear();
	es.clear(), es1.clear();
}

void solve() {
	scanf("%lld", &T);
	while (T--) {
		init();
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= m; i++) {
			LL a, b, c;
			scanf("%lld%lld%lld", &a, &b, &c);
			g[a].push_back(Edge(a, b, c));
			es.push_back(Edge(a, b, c));
		}
		dijkstra();
		if (dis[n] >= INF) {
			puts("0");
			continue;
		}
		getNewG();
		s = 1, t = n;
		printf("%lld\n", dinic());
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
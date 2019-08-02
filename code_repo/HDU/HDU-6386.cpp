/*

题意：无向图，n个点，m个边，每条边有边权。若从一条ci的边到另一cj（ci!=cj）的边，则代价+1（路径上的第一条边走完已经有为1的代价。。）。需要找一条从1到n的路径，使代价最小

解：相当于使用BFS找最短路，然后每次代价+1是边权不相同时，所以使用DFS把和某次BFS时走的边的边权相同的点都标记
看代码qwq。。。

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 4e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w, next;
} es[MAX_M];
int n, m, tot, head[MAX_N], dis[MAX_N];
bool vis[MAX_N];
queue<int> Q;

inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
}

inline void init() {
	memset(head, 0, sizeof(head));
	tot = 0;
}

void DFS(int u, int uW) {
	for (int i = head[u]; i; i = es[i].next) {
		int v = es[i].v, w = es[i].w;
		if (!vis[v] && uW == w){ 
			dis[v] = dis[u];
			vis[v] = 1;
			Q.push(v);
			DFS(v, uW);
		}
	}
}

inline void BFS() {
	while(Q.size()) Q.pop();
	memset(vis, 0, sizeof(vis));
	Q.push(1);
	vis[1] = 1;
	dis[1] = 0;
	dis[n] = INF;
	while(Q.size()) {
		int u = Q.front(); Q.pop();
		for (int i = head[u]; i; i = es[i].next) {
			int v = es[i].v, w = es[i].w;
			if (vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			Q.push(v);
			DFS(v, w);
		}
		if (dis[n] < INF) break;
	}
}

void solve() {
	while (~scanf("%d%d", &n, &m)) {
		init();
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
			addEdge(b, a, c);
		}
		BFS();
		if (dis[n] >= INF) puts("-1");
		else printf("%d\n", dis[n]);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
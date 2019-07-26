/*

题意：找到从1到n的路径，使边数最少，ci序列的字典序最小

解：从n倒着bfs，得到i到n的最短路d[i]，再从1开始按d[i]层次贪心选择ci最小的边的终点进行bfs

*/

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <iostream>

typedef long long LL;

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct edge {
	int v, c, next;
} e[MAX_M << 1];
int n, m, tot, head[MAX_N], d[MAX_N], ans[MAX_M];
bool vis[MAX_N];
queue<int> q;
vector<int> tmp1, tmp2;

inline void addEdge(int u, int v, int c) {
	e[++tot].v = v, e[tot].c = c, e[tot].next = head[u], head[u] = tot;
}

void bfs1() {
	memset(d, 0xff, sizeof(d));
	while (q.size()) q.pop();
	d[n] = 0;
	q.push(n);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

void bfs2() {
	memset(vis, 0, sizeof(vis));
	tmp1.clear();
	tmp1.push_back(1);
	vis[1] = 1;
	for (int i = 1; i <= d[1]; i++) {
		int minColor = INF;
		for (int j = 0; j < tmp1.size(); j++) {
			int u = tmp1[j];
			for (int k = head[u]; k; k = e[k].next) {
				if (d[u] == d[e[k].v] + 1) {
					minColor = min(minColor, e[k].c);
				}
			}
		}
		ans[i] = minColor;
		tmp2.clear();
		for (int j = 0; j < tmp1.size(); j++) {
			int u = tmp1[j];
			for (int k = head[u]; k; k = e[k].next) {
				if (d[u] == d[e[k].v] + 1 && !vis[e[k].v] && e[k].c == minColor) {
					vis[e[k].v] = 1;
					tmp2.push_back(e[k].v);
				}
			}
		}
		tmp1 = tmp2;
	}
}

inline void init() {
	tot = 0;
	memset(head, 0, sizeof(head));
	memset(e, 0, sizeof(e));
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
		bfs1();
		printf("%d\n", d[1]);
		bfs2();
		for (int i = 1; i <= d[1]; i++) {
			if (i != 1) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
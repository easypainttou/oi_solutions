/*

题意：n个第1天的数xi，m个第2天的数yi，aij表示xi和yj之间的大小关系，求这些数，要求最大的数最小

解：先用并查集合并相等的数来缩点，再按照大于或者小于的关系对这些点连边，再拓扑排序。。。
（之前不会处理等于关系，想到了tarjan qwq。。。

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e3 + 5;
const int MAX_M = 4e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, next;
} es[MAX_N * MAX_N];
int n, m, fa[MAX_N << 1], cnt1, tot, head[MAX_N << 1], ind[MAX_N << 1], eval[MAX_N << 1], cnt2;
char g[MAX_N][MAX_N];
queue<int> Q;

inline void addEdge(int u, int v) {
	es[++tot].v = v, es[tot].next = head[u], head[u] = tot;
}

int findFa(int x) {
	return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}

void topoSort() {
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		for (int i = head[u]; i; i = es[i].next) {
			int v = es[i].v;
			if (--ind[v] == 0) Q.push(v), cnt2++;
			eval[v] = max(eval[v], eval[u] + 1);
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + m; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == '=') {
				fa[findFa(i)] = findFa(j + n);
			}
		}
	}
	for (int i = 1; i <= n + m; i++) if (findFa(i) == i) cnt1++;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == '>') {
				addEdge(fa[j + n], fa[i]);
				ind[fa[i]]++;
			} else if (g[i][j] == '<') {
				addEdge(fa[i], fa[j + n]);
				ind[fa[j + n]]++;
			}
		}
	}
	for (int i = 1; i <= n + m; i++) {
		if (fa[i] == i && !ind[i]) {
			Q.push(i);
			cnt2++;
			eval[i] = 1;
		}
	}
	topoSort();
	if (cnt1 == cnt2) {
		puts("Yes");
		for (int i = 1; i <= n; i++) {
			if (i != 1) printf(" ");
			printf("%d", eval[fa[i]]);
		} puts("");
		for (int i = 1 + n; i <= m + n; i++) {
			if (i != 1 + n) printf(" ");
			printf("%d", eval[fa[i]]);
		} puts("");
	} else {
		puts("No");
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
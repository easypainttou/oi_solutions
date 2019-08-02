/*

题意：n个门，m个锁，每个门都被2个锁控制，给出门的初始状态，判断是否能使门都打开

解：每个门都被2个锁控制，若门初始是开的，则2个锁一个开另一个开，或一个关另一个关，若门初始是关的，则2个锁一个开另一个关，或一个关另一个开，这样就能用2-sat

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 1400 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w, next;
} es[MAX_N << 2];
int n, m, tot, head[MAX_N << 1], cnt, dfn[MAX_N << 1], low[MAX_N << 1], stk[MAX_N << 1], sp, cCnt, clr[MAX_N << 1], state[MAX_N];
bool instk[MAX_N << 1];
vector<int> locked[MAX_N];

inline void addEdge(int u, int v ){
	es[++tot].v = v, es[tot].next = head[u], head[u] = tot;
}

inline void addPair(int u, int v) {
	addEdge(u, v), addEdge(v, u);
}

void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	stk[++sp] = x;
	instk[x] = 1;
	for (int i = head[x]; i; i = es[i].next) {
		int v = es[i].v;
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		} else if (instk[v]) {
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (dfn[x] == low[x]) {
		++cCnt;
		do {
			clr[stk[sp]] = cCnt;
			instk[stk[sp]] = 0;
		} while(stk[sp--] != x);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", state + i);
	}
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++) {
			int id;
			scanf("%d", &id);
			locked[id].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (state[i]) {
			addPair(locked[i][0] << 1, locked[i][1] << 1);
			addPair((locked[i][0] << 1) - 1, (locked[i][1]<< 1) - 1);
		} else {
			addPair((locked[i][0] << 1) - 1, locked[i][1] << 1);
			addPair((locked[i][0] << 1), (locked[i][1]<< 1) - 1);
		}
	}
	for(int i = 1; i <= m << 1; i++) if(!dfn[i]) tarjan(i);
	bool f = 1;
	for (int i = 1; i <= m; i++) {
		if (clr[i << 1] == clr[(i << 1) -1]) {
			f = 0;
			break;
		}
	}
	if (f) {
		puts("YES");
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
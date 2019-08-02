/*

题意：一个n个点的树，a和b有边权c的边，2个人从s点出发，走完每条边，不用回到起点，求走的路的总长度之和最小值

解：
只有1个，答案是 边权和*2-从s出发能走到的最远距离
有2个，答案是 边权和*2-树的直径
（s在或不在树的直径上都是这个答案qwq。。。）

还有一个k个人的，见HDU4003

*/

#include <cstdio>

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 4e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int v, w, next;
} es[MAX_N << 1];
int n, s, tot, head[MAX_N], len, ans, pos;

inline void addEdge(int u, int v, int w) {
	es[++tot].v = v, es[tot].w = w, es[tot].next = head[u], head[u] = tot;
}

void DFS(int f, int u, int dep) {
	if (len < dep) {
		len = dep;
		pos = u;
	}
	for (int i = head[u]; i; i = es[i].next) {
		int v = es[i].v, w = es[i].w;
		if (v == f) continue;
		DFS(u, v, dep + w);
	}
}

void solve() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addEdge(a, b, c);
		addEdge(b, a, c);
		ans += c << 1;
	}
	DFS(s, s, 0);
	len = 0;
	DFS(pos, pos, 0);
	ans -=len;
	printf("%d", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
/*

题意：n个任务，起始时间s，持续时间t，收益c，现在有k个机器，1个机器如果开始一个任务，那么在s到s+t-1这段时间不能做其他任务。求收益最大时需要做哪些任务

解：一个源点s，一个汇点t，一个结点T，每个任务u拆成2个点u和u'。首先任务按照起始时间排序，排序后结点u编号为1~n，u'为n+1~2n，s向1连容量INF费用0的边，每个i向i+1(1<=i<n)连容量INF费用0的边，i向i+n(1<=i<=n)连容量1费用-ci的边，i+n向T连容量INF费用0的边，T向t连容量k费用0的边，i+n向j（j是起始时间大于i结束时间的任务，起始时间最小。若没有就不连）连容量INF费用0的边，跑最小费用最大流qwq

RE为什么返回的是T。。。 qwq

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 2e3 + 5;
const int MAX_M = 1e4 + 5;
const int INF = 0x3f3f3f3f;

struct Task {
	int s, t, c, id;
	
	bool operator<(const Task & a) {
		return s < a.s;
	}
} ts[MAX_N]; 

struct Edge {
	int u, v, f, c, next;
} es[MAX_M];
int n, k, tot = 1, head[MAX_N], s, T, t, dis[MAX_N], flow[MAX_N], pre[MAX_N], ans[MAX_N];
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
		while (u != s) { 
			es[pre[u]].f -= flow[t];
			es[pre[u]^1].f += flow[t];
			u = es[pre[u]].u;
		}
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		ts[i].id = i;
		scanf("%d%d%d", &ts[i].s, &ts[i].t, &ts[i].c);
		ts[i].t += ts[i].s - 1;
	}
	sort(ts + 1, ts + n + 1);
	s = 2 * n + 1, T = 2 * n + 2, t = 2 * n + 3;
	addPair(s, 1, INF, 0);
	addPair(T, t, k, 0);
	inc(i, 1, n) {
		if(i < n) addPair(i, i + 1, INF, 0);
		addPair(i, i + n, 1, -ts[i].c);
		addPair(i + n, T, INF, 0);
		inc(j, i + 1, n) {
			if (ts[i].t < ts[j].s) {
				addPair(i + n, j, INF, 0);
				break;
			}
		}
	}
	MCMF();
	inc(u, 1, n) {
		for (int j = head[u]; j; j = es[j].next) {
			if (es[j].v == u + n) {
				ans[ts[u].id] = 1 - es[j].f;
				break;
			}
		}
	}
	inc(i, 1, n) {
		printf("%d ", ans[i]);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
/*

题意：平面上有n个点，m条边，第i条边连接ui和vi，破坏第i条边需要wi的费用。要求平面上任意一处都能被访问，需要破坏尽量少的边，在边最少的前提下费用最少。求边数和费用

解：
题目要求是求平面图的对偶图的最小生成树。
根据欧拉公式，有k个连通分量的平面图，区域数R=E-V+k+1
对偶图生成树的边数R-1，所以保留下来的边数为V-k，然后V-k恰好是k个连通分量的最小生成树的边数和，所以只要求原图的最大生成树，然后减一下。。。
qwq

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 5;
const int MAX_M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
	int u, v, w;

	bool operator<(const Edge & a) {
		return w > a.w;
	}
} es[MAX_M];
int n, m, fa[MAX_N], ans, cnt;

int findFa(int x) {
	return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}

int kruskal() {
	int res = 0;
	inc(i, 1, n) fa[i] = i;
	sort(es + 1, es + m + 1);
	inc(i, 1, m) {
		int uf = findFa(es[i].u), vf = findFa(es[i].v);
		if (uf != vf) {
			fa[uf] = vf;
			res += es[i].w;
			cnt++;
		}
	}
	return res;
}

void solve() {
	while (~scanf("%d%d", &n, &m)) {
		ans = cnt = 0;
		inc(i, 1, n) {
			int x, y;
			scanf("%d%d", &x, &y);
		}
		inc(i, 1, m) {
			scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
			ans += es[i].w;
		}
		ans -= kruskal();
		printf("%d %d\n", m - cnt, ans);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
/*

题意：n个ci，给m对l、r，要求改变cl或cr，使cl和cr相同，最少改多少个

解：ci做结点，cl、cr之间连边，发现一个连通块的ci应相同，也就是一个连通块需要改变的ci个数为连通块大小减去出现最多的ci的出现次数
使用了并查集和map
qwq

*/

#include <cstdio>
#include <map>

typedef long long LL;

using namespace std;

const int MAX_N = 2e5 + 5;

int n, m, k, c[MAX_N], fa[MAX_N], maxn[MAX_N], ans;
map<int, map<int, int> > mp;

int findFa(int x) {
	return fa[x] == x ? x : fa[x] = findFa(fa[x]);
}

void solve() {
	scanf("%d%d%d",&n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		fa[findFa(l)] = findFa(r);
	}
	for (int i = 1; i <= n; i++) {
		int f = findFa(i);
		maxn[f] = max(maxn[f], ++mp[f][c[i]]);
	}
	ans = n;
	for (int i = 1; i <= n; i++) {
		if (findFa(i) == i) ans -= maxn[i];
	}
	printf("%d", ans);
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
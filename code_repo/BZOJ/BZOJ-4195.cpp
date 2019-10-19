/*

题意：给出n个约束，xi==xj或xi!=xj，判断是否同时满足

解：数据范围1e9，不同数字的个数最多2e6，所以用map离散化，然后使用并查集，对所有xi==xj合并i和j，再对所有xi!=xj检查i和j是否在同一个集合，若存在在同一个集合的则NO，否则YES

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e6 + 5;

bool f;
int t, n, fa[MAX_N << 1], e[MAX_N], xi[MAX_N], xj[MAX_N], tot;
map<int, int> mp;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void solve() {
	scanf("%d", &t);
	while (t--) {
		mp.clear(), tot = 0, f = 0;
		scanf("%d", &n);
		inc(i, 1, n) {
			scanf("%d%d%d", xi + i, xj + i, e + i);
			if (!mp[xi[i]]) mp[xi[i]] = ++tot;
			if (!mp[xj[i]]) mp[xj[i]] = ++tot;
		}
		inc(i, 1, tot) fa[i] = i;
		inc(i, 1, n) {
			if (e[i]) {
				int x = mp[xi[i]], y = mp[xj[i]], xf = find(x), yf = find(y);
				if (xf != yf) fa[xf] = yf;
			}
		}
		inc(i, 1, n) {
			if (!e[i]) {
				int x = mp[xi[i]], y = mp[xj[i]], xf = find(x), yf = find(y);
				if (xf == yf) {
					f = 1;
					break;
				}
			}
		}
		puts(f ? "NO" : "YES");
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}
/*

题意：n个ui，求一个最大的x，使u1~ux中去掉一个，可以使同一ui出现的次数相等

解：思维题qwq不易想到qwq。。。不太理解
easy的ui只有10种，可能暴力也能过？hard就不行了。。。

*/

#include <cstdio>

using namespace std;

const int MAX_N = 1e5 + 5;

int n, u, cnt[MAX_N], cntOfCnt[MAX_N], ans = 1;

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &u);
		cnt[u]++;
		cntOfCnt[cnt[u]]++;
		if (i < n && cnt[u] * cntOfCnt[cnt[u]] == i) ans = i + 1;
		else if (cnt[u] * cntOfCnt[cnt[u]] == i - 1) ans = i;
	}
	printf("%d", ans);
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
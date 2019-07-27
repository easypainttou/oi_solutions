/*

题意：给n个xi，求满足xi-xj>=z的最大匹配

解：尺取法

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;

int n, z, x[MAX_N];

void solve() {
	scanf("%d%d", &n, &z);
	for (int i = 1; i <= n; i++) scanf("%d", x + i);
	sort(x + 1, x + n + 1);
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		if (x[i] - x[cur] >= z) cur++;
	}
	printf("%d", min(n / 2, cur - 1));
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
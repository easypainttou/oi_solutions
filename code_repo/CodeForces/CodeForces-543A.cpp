/*

题意：m行代码，n个程序员，第i个程序员每行ai个bug。若第i个程序员写vi行代码，求总bug数不超过b的方案数

解：二维完全背包
qwq当场写了一个mle的解法。。。

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 500 + 5;
const int INF = 0x3f3f3f3f;

LL n, m, a, b, mod, dp[MAX_N][MAX_N], ans;

void solve() {
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &b, &mod);
	dp[0][0] = 1;
	for (LL i = 1; i <= n; i++) {
		scanf("%I64d", &a);
		for (LL j = 1; j <= m ; j++) {
			for (LL k = a; k <= b ; k++) {
				dp[j][k] += dp[j - 1][k - a];
				dp[j][k] %= mod;
			}
		}
	}
	for (LL i = 0; i <= b; i++) ans += dp[m][i], ans %= mod;
	printf("%I64d", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
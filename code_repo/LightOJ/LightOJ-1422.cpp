/*

题意：n个派对，第i个要穿编号ai的衣服，可以选择穿上或脱下衣服（只要不脱下就可复用），求最少需要的衣服数量

解：
区间dp
dp[i][j]指从第i个到第j个派对最少衣服数量
初值 dp[i][i]=1
转移方程
dp[i][j]=dp[i+1][j]+1
a[i]==a[i+1],dp[i][j]=min(dp[i][j],dp[i+1][j])
a[i]==a[k],dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j])
目标 dp[1][n]

*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 5;
const double EPS = 1e-10;

int T, n, a[MAX_N], dp[MAX_N][MAX_N];

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", a + i), dp[i][i] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j + i - 1 <= n; ++j) {
				int L = j, R = j + i - 1;
				dp[L][R] = dp[L + 1][R] + (a[L] == a[L + 1] ? 0 : 1);
				for (int k = L + 2; k <= R; ++k) {
					if (a[L] == a[k]) dp[L][R] = min(dp[L][R], dp[L + 1][k - 1] + dp[k][R]);
				}
			}
		}
		printf("Case %d: %d\n", kase, dp[1][n]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
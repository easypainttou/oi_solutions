/*

题意：n个整数，每次选一个a[i]（不能选第1个或第n个），分数加上a[i-1]*a[i]*a[i+1]，直到最后剩下第1个和第n个，求最小分数

解：
区间dp
dp[i][j]指取i到j之间的数，最后剩下i和j，的最小分数
初值 dp[i][i+1]=0
转移方程
dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[k]*a[j])
目标 dp[1][n]

*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;

int n, a[MAX_N], dp[MAX_N][MAX_N];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 3; i <= n; ++i) {
		for (int j = 1; j + i - 1 <= n; ++j) {
			int L = j, R = j + i -1;
			dp[L][R] = INF;
			for (int k = L + 1; k < R; ++k) {
				dp[L][R] = min(dp[L][R], dp[L][k] + dp[k][R] + a[L] * a[k] * a[R]);
			}
		}
	}
	printf("%d", dp[1][n]);
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
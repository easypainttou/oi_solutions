/*

题意：求括号字符串s的最长合法子序列的长度

解：
区间dp
dp[i][j]指si...sj子串上的最长合法子序列的长度
初值 dp[i][i]=0
转移方程
dp[i][j]=dp[i+1][j]
si和sk匹配，dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+2)
目标 dp[1][n]

*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 5;
const double EPS = 1e-10;

char a[MAX_N];
int n, dp[MAX_N][MAX_N];

void solve() {
	while (1) {
		scanf("%s", a + 1);
		if (a[1] == 'e') break;
		n = strlen(a + 1);
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j + i - 1 <= n; ++j) {
				int L = j, R = j + i - 1;
				dp[L][R] = dp[L + 1][R];
				for (int k = L + 1; k <= R; ++k) {
					if (a[L] == '(' && a[k] == ')' || a[L] == '[' && a[k] == ']') dp[L][R] = max(dp[L][R], dp[L + 1][k - 1] + dp[k + 1][R] + 2);
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
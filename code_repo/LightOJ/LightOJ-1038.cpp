/*

题意：有一个大于1的整数D，随机选一个D的约数除D，得到的数作为新的D，重复这个操作，直到为1，求期望的步数

解：
dp[D]指从D到1的期望的步数
设D有k个约数
dp[D]=1/k*(dp[1]+...dp[Di]+...+dp[D(k-1)]+dp[D])+1
转移方程 dp[D]=(dp[1]+...dp[Di]+...+dp[D(k-1)]+k)/(k-1)

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e5+10;
const int MAX_M = 200+10;
const int INF = 0x3f3f3f3f;

int T, n;
double dp[MAX_N];

inline void init() {
	for (int i = 2; i <= int(1e5); ++i) {
		int sq = sqrt(i), num = 2;
		double sum = 0;
		for (int j = 2; j <= sq; ++j) {
			if (i % j == 0) {
				++num;
				sum += dp[j];
				if (i / j == j) continue;
				++num;
				sum += dp[i / j];
			}
		}
		dp[i] = (num + sum) / (num - 1);
	}
}

void solve() {
	init();
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n);
		printf("Case %d: %f\n", kase, dp[n]);
	}
}

int main() {
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
/*

题意：n个小时，第i个小时恢复ui的体力，第n个小时和第1个小时是相连的，选择其中b（b<n）个小时休息，不一定连续，可以分成若干段，每一段的第1个小时不能恢复体力。求恢复体力的最大值

解：
dp[i][j][0]为考虑到第i个小时，已经休息j小时，第i个小时不休息，的最大体力
dp[i][j][1]为考虑到第i个小时，已经休息j小时，第i个小时休息，的最大体力
转移方程
dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1])
dp[i][j][1]=max(dp[i-1][j-1][0],dp[i-1][j-1][1]+u[i])
n个小时环形的，所以每个i为起点都推一边
时间复杂度O(n^3)
考虑优化
只考虑起点为1，初始值dp[1][0][0]=dp[1][1][1]=0，然后i从从2推到n，用max(dp[n][b][0],dp[n][b][1])更新答案，然而这样第1个小时不能恢复体力，所以令第1小时恢复体力，第n小时休息，初始值dp[1][1][1]=u[1]，这样再推一遍，用dp[n][b][1]更新答案
i这一维可以滚动数组优化
时间复杂度O(n^2)

*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 3830 + 5;
const int INF = 0x3f3f3f3f;

int n, b, u[MAX_N], dp[2][MAX_N][2], ans;

inline void init() {
	for (int i = 0; i < b; i++) dp[1][i][0] = dp[1][i][1] = -INF;
}

inline void getDp() {
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= b; j++) {
			dp[i & 1][j][0] = max(dp[i - 1 & 1][j][0], dp[i - 1 & 1][j][1]);
			dp[i & 1][j][1] = j > 0 ? max(dp[i - 1 & 1][j - 1][0], dp[i - 1 & 1][j - 1][1] + u[i]) : -INF;
		}
	}
}

void solve() {
	scanf("%d%d", &n, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", u + i);
	}
	init(), dp[1][0][0] = dp[1][1][1] = 0, getDp();
	ans = max(dp[n & 1][b][0], dp[n & 1][b][1]);
	init(), dp[1][1][1] = u[1], getDp();
	printf("%d", max(ans, dp[n & 1][b][1]));
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
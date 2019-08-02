/*

题意：N个空格，每个空格填入{0,1,2,3}中的一个数，有M个条件必须满足，第i个条件要求在[li,ri]之间有xi个不同的数，求填入空格的方法数

解：
dp[i][j][k][t]代表填完前t个位置，4个数字最后一次出现的位置从小到大排序后为i,j,k,t的方案数。
首先dp[0][0][0][0]=1
对于dp[i][j][k][t]，若某个条件ri==t，则计算4个数最后一次出现的位置>=li的数的个数，若个数不等于xi，令dp[i][j][k][t]=0
然后进行转移
dp[i][j][k][t+1]+=dp[i][j][k][t]
dp[i][j][t][t+1]+=dp[i][j][k][t]
dp[i][k][t][t+1]+=dp[i][j][k][t]
dp[j][k][t][t+1]+=dp[i][j][k][t]

直接这样会T。因为t只会影响t+1，所以滚动最后一维，空间复杂度由O(n^4)变为O(n^3)（减少了赋初值的时间？qwq）

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 100 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

LL T, n, m, dp[MAX_N][MAX_N][MAX_N][2], sum, a[2];
vector< pair<LL, LL> > R[MAX_N];

inline void init() {
	for (int i = 1; i < MAX_N; i++) R[i].clear();
	sum = 0;
	a[0] = 0, a[1] = 1;
}

inline bool check(int i, int j, int k, int t) {
	for (int r = 0; r < R[t].size(); r++) {
		LL L = R[t][r].first, x = R[t][r].second;
		if((i >= L) + (j >= L) + (k >= L) + 1 != x) return 0;
	}
	return 1;
}

void solve() {
	scanf("%lld", &T);
	while (T--) {
		init();
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= m; i++) {
			LL a, b, c;
			scanf("%lld%lld%lld", &a, &b, &c);
			R[b].push_back(make_pair(a, c)); //每个以b为右端点的区间都要考虑qwq
		}
		dp[0][0][0][0] = 1;
		for (int t = 0; t <= n; t++) {
			for (int k = 0; k < max(1, t + 1); k++) {
				for (int j = 0; j < max(1, k); j++) {
					for (int i = 0; i < max(1, j); i++) {
						dp[i][j][k][a[1]] = 0;
					}
				}
			}
			for (int k = 0; k < max(1, t); k++) {
				for (int j = 0; j < max(1, k); j++) {
					for (int i = 0; i < max(1, j); i++) {
						if (check(i, j, k, t)) {
							dp[i][j][k][a[1]] = (dp[i][j][k][a[1]] + dp[i][j][k][a[0]]) % MOD;
							dp[i][j][t][a[1]] = (dp[i][j][t][a[1]] + dp[i][j][k][a[0]]) % MOD;
							dp[i][k][t][a[1]] = (dp[i][k][t][a[1]] + dp[i][j][k][a[0]]) % MOD;
							dp[j][k][t][a[1]] = (dp[j][k][t][a[1]] + dp[i][j][k][a[0]]) % MOD;
						} else dp[i][j][k][a[0]] = 0;
						if (t == n) sum = (sum + dp[i][j][k][a[0]]) % MOD;
					}
				}
			}
			swap(a[0], a[1]);
		}
		printf("%lld\n", sum);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
/*

题意：有N个银行，第j个有Mj的钱，有Pj的被捕的概率，选择其中一些使被捕概率<P，获得钱最多

解：01背包，因为概率是实数，所以将概率作为价值，钱作为容量，最后遍历一下qwq

*/

#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 100 + 5;
const int INF = 0x3f3f3f3f;

int T, n, m[MAX_N], sum, ans;
double P, p[MAX_N], dp[MAX_N * MAX_N];

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		sum = 0;
		scanf("%lf%d", &P, &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%lf", m + i, p + i);
			sum += m[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = sum; j >= m[i]; --j) {
				dp[j] = max(dp[j], dp[j - m[i]] * (1 - p[i]));
			}
		}
		for (int i = sum; i >= 0; --i) {
			if (dp[i] > 1 - P) {
				ans = i;
				break;
			}
		}
		printf("Case %d: %d\n", kase, ans);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
/*

题意：N个银行，每个银行有Mi的钱，pi的被抓的概率。求被抓的概率需要低于P的最多能获得的钱数

解：01背包，然而直接做容量就是浮点数，所以
考虑前i个银行，钱数不超过j，不被抓的最大概率
dp[i][j]=max(dp[i-1][j], dp[i-1][j-M[i]]*(1-p[i]))
求完后从大到小遍历j，求第一个满足1-dp[i][j]小于P的j
qwq

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 100 + 5;

int T, N, M[MAX_N], sum;
double P, p[MAX_N], dp[MAX_N * MAX_N];


void solve() {
	scanf("%d", &T);
	while (T--) {
		sum = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%lf%d", &P, &N);
		inc(i, 1, N) scanf("%d%lf", M + i, p + i), sum += M[i];
		dp[0] = 1;
		inc(i, 1, N) {
			dec(j, sum, M[i]) {
				dp[j] = max(dp[j], dp[j - M[i]] * (1 - p[i]));
			}
		}
		dec(i, sum, 0) {
			if (1 - dp[i] < P) {
				printf("%d\n", i);
				break;
			}
		}
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
/*

题意：n个物品，每个重量wi，选择其中k对，定义一对的代价是2个wi之差的平方，使所有对的代价的和最小

解：先对wi排序，dp[i][j]是考虑到第i个物品，选j对的最小代价，dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(w[i]-w[i-1])^2)

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
int n, k, w[MAX_N], dp[MAX_N][MAX_N];

void solve() {
	while (~scanf("%d%d", &n, &k)) {
		inc(i, 1, n) {
			scanf("%d", w + i);
		}
        sort(w + 1, w + n + 1);
		//↓比memset快 qwq
		inc(i, 1, n) {
            inc(j, 0, k) {
                dp[i][j] = INF;
            }
        }
		//dp[0][0] = 0;
		inc(i, 1, n) {
			for (int j = 0; j << 1 <= i && j <= k; j++) {
				if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				if (i > 1 && j > 0) dp[i][j] = min(dp[i][j],dp[i - 2][j - 1] + (w[i] - w[i -1]) * (w[i] - w[i - 1]));
			}
		}
		printf("%d\n", dp[n][k]);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
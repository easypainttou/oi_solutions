/*

题意：长度为n的数组c，每次可以删除一个回文子串，剩下的部分拼在一起，求全部删除需要的最少步数

解：dp[i][j]指删除区间[i, j]需要的最少步数
dp[i][j] = dp[i+1][j] + 1
若a[i] == a[i + 1]，dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
若a[i] == a[k]，dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j])   i+1<k<=j

*/

#include <cstdio>
#include <cstring>
#include <queue>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 500 + 10;
const int MAX_M = 3e4 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

int n, a[MAX_N], dp[MAX_N][MAX_N];

void solve() {
    scanf("%d", &n);
    inc(i, 1, n) {
        scanf("%d", a + i);
    } 
    inc(len, 1, n) {
        for (int i = 1; i +len - 1<= n; i++) {
            int j = i + len -1;
            dp[i][j] = dp[i + 1][j] + 1;
            if (a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], dp[i + 2][j] + 1);
            for (int k = i + 2; k <= j; k++) {
                if (a[i] == a[k]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}
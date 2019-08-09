/*

题意：n个元素的数组S，求m个不相交的子段的和的最大值

解：（题目描述不清，没说m的范围，大概看一下思路。。。
考虑前j个，分成i个子段，最后一个子段的最后一个是j
dp[i][j]=max(dp[i][j-1],dp[i-1][k])+s[j] i-1<=k<=j-1
然后dp数组太大了，需要优化
pre[j-1]为max(dp[i-1][k]) i-1<=k<=j-1
然后去掉i这个维度
dp[j]=max(dp[j-1],pre[j-1])+s[j]

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int m, n, s[MAX_N], dp[MAX_N], pre[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

void solve() {
	while (~scanf("%d%d", &m, &n)) {
		inc(i, 1, n) {
			dp[i] = pre[i] = 0;
			s[i] = read();
		}
		int tmp;
		inc(i, 1, m) {
			tmp = -INF;
			inc(j, i, n) {
				dp[j] = max(dp[j - 1], pre[j - 1]) + s[j];
				pre[j - 1] = tmp;
				tmp = max(tmp, dp[j]);
			}
		}
		printf("%d\n", tmp);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
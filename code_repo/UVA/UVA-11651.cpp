/*

题意：数字系统的进制base在2~6之间，一个数字的相邻数位数字不同，没有前导0，一个数字有一个分数，分数score为相邻2个数位的差的平方的和，现在给出base和score，求共有多少数字在base进制下的分数为score，取模2^32

解：
dp[i][j]为score为i，最后一位为j的数字个数
初值 dp[0][j]=1
转移方程 dp[i+(j-k)^2][j]+=dp[i][k]
求dp[score][0]+...+dp[score][base-1]
score范围1e9
所以使用矩阵快速幂加速递推
具体见
https://www.cnblogs.com/AOQNRMGYXLMV/p/5256508.html
qwq

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int LL; //MOD 1<<32，自动溢出qwq，不然超时？

const int MAX_N = 150 + 5;
const int MAX_M = 30 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int T, base, score, N;
LL f[MAX_N], dp[MAX_M][6], ans[MAX_N];

struct Matrix {
	LL a[MAX_N][MAX_N];
	int n;
	
	Matrix(int n = 0):n(n) {
		memset(a, 0, sizeof(a));
	}
	
	Matrix operator*(const Matrix & b) {
		Matrix tmp(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					tmp.a[i][j] += a[i][k] * b.a[k][j];
				}
			}
		}
		return tmp;
	}
} a, e;

inline void matrixQPow(int b) {
	e.n = N;
	memset(e.a, 0, sizeof(e.a));
	for (int i = 1; i <= N; ++i) e.a[i][i] = 1;
	while (b) {
		if (b & 1) e = e * a;
		a = a * a;
		b >>= 1;
	}
}

inline void mulF() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			ans[i] += e.a[i][j] * f[j];
		}
	}
}

inline void init() {
	memset(f, 0, sizeof(f));
	memset(dp, 0, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	memset(a.a, 0, sizeof(a.a));
}

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		init();
		scanf("%d%d", &base, &score);
		N = (base - 1) * (base  - 1) * base;
		int s = (base - 1) * (base - 1);
		a.n = N;
		for (int i = 1; i < base; ++i) dp[0][i] = 1; //没有前导零
		for (int i = 0; i < s; ++i) {
			for (int j = 0; j < base; ++j) {
				for (int k = 0; k < base; ++k) {
					LL d = (k - j) * (k - j);
					if (!d || i + d > s) continue;
					dp[i + d][j] += dp[i][k];
				}
			}
		}
		if (score <= s) {
			LL res = 0;
			for (int i = 0; i < base; ++i) res += dp[score][i];
			printf("Case %d: %u\n", kase, res);
			continue;
		}
		for (int i = 0; i < s; ++i) {
			for (int j = 0; j < base; ++j) {
				f[base * i + j + 1] = dp[i][j];
			}
		}
		for (int i = 1; i < s; ++i) {
			for (int j = 1; j <= base; ++j) {
				a.a[(i - 1) * base + j][i * base + j] = 1;
			}
		}
		for (int i = 0; i < base; ++i) {
			int t = base * (s - 1) + i + 1;
			for (int j = 0; j < base; ++j) {
				if (i == j) continue;
				int b = (i - j) * (i - j);
				a.a[t][base * (s - b) + 1 + j] = 1;
			}
		}
		matrixQPow(score);
		mulF();
		LL res = 0;
		for (int i = 0; i < base; ++i) res += ans[i + 1];
		printf("Case %d: %u\n", kase, res);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
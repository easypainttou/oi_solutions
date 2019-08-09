/*

题意：M行N列的区域，每一个格子里是R或F，求只包含F的最大的矩形

解：最大子矩阵问题
做法是用height[i][j]记录i行j列的格子从它到第一个遇到的R或边界的距离
L[j]记录第i行的第j列的格子最左能够到的位置，也就是对于L[j]<=k<j，满足height[k]>=height[j]，而L[j]-1不满足
R[j]记录第i行的第j列的格子最右能够到的位置
然后枚举每个格子，用(R[j]-L[j]+1)*height[i][j]更新答案
答案再乘3
qwq

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e3 + 5;

int K, n, m, height[MAX_N][MAX_N], L[MAX_N], R[MAX_N], ans;
char s[5];

inline void init() {
	memset(height, 0, sizeof(height));
	ans = 0;
}

void solve() {
	scanf("%d", &K);
	while (K--) {
		init();
		scanf("%d%d", &n, &m);
		inc(i, 1, n) {
			height[i][0] = height[i][m + 1] = -1;
			inc(j, 1, m) {
				scanf("%s", s);
				if (s[0] == 'R') {
					height[i][j] = 0;
				} else {
					height[i][j] = height[i - 1][j] + 1;
				}
			}
		} 
		inc(i, 1, n) {
			inc(j, 1, m) L[j] = j, R[j] = j;
			inc(j, 1, m) {
				while (height[i][L[j] - 1] >= height[i][j]) L[j] = L[L[j] - 1];
			}
			dec(j, m, 1) {
				while (height[i][R[j] + 1] >= height[i][j]) R[j] = R[R[j] + 1];
			}
			inc(j, 1, m) {
				ans = max(ans, (R[j] - L[j] + 1) * height[i][j]);
			}
		}
		printf("%d\n", ans * 3);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
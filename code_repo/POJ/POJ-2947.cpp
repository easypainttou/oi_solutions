/*

题意：n种部件，m条记录，每条记录说明从周几到周几（可能隔了几周）建造哪些部件，求建造每种部件需要的时间（范围在3~9天）

解：
高斯消元解同余方程组 qwq
每个方程类似 a1x1+...+anxn=一周内天数的差 mod 7

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 300 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 7;
const double EPS = 1e-6;

char s[5];
int n, m, a[MAX_N][MAX_N], ans[MAX_N];

inline int getWeek() {
	if (s[0] == 'M') return 1;
	if (s[0] == 'T' && s[1] == 'U') return 2;
	if (s[0] == 'W') return 3;
	if (s[0] == 'T' && s[1] == 'H') return 4;
	if (s[0] == 'F') return 5;
	if (s[0] == 'S' && s[1] == 'A') return 6;
	if (s[0] == 'S' && s[1] == 'U') return 7;
	return 0;
}

int exgcd(int a, int b, int & x, int & y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

//0-无解 1-唯一 2-无穷
int gauss() {
	int rank = 1;
	for (int i = 1; rank <= m && i <= n; ++rank, ++i) {
		int r = rank;
		for (int j = rank + 1; j <= m; ++j) {
			if (abs(a[j][i]) > abs(a[r][i])) r = j;
		}
		if (a[r][i] == 0) {
			--rank;
			continue;
		}
		if (r != rank) for(int j = i; j <= n + 1; ++j) swap(a[rank][j], a[r][j]);
		for (int j = rank + 1; j <= m; ++j) {
			if (a[j][i] == 0) continue;
			int l = lcm(abs(a[rank][i]), abs(a[j][i])), ta = l / a[rank][i], tb = l / a[j][i]; //解为整数，所以这样消元
			for (int k = i; k <= n + 1; ++k) {
				a[j][k] = a[j][k] * tb - a[rank][k] * ta;
				a[j][k] = (a[j][k] % MOD + MOD) % MOD;
			}
		}
	}
	for (int i = rank; i <= m; ++i) if (a[i][n + 1]) return 0; //无解，wa在这里qwq
	if (rank - 1 < n)	return 2; //无穷解
	for (int i = n; i >= 1; --i) {
		ans[i] = a[i][n + 1];
		for (int j = i + 1; j <= n; ++j) {
			ans[i] -= ans[j] * a[i][j];
			ans[i] = (ans[i] % MOD + MOD)% MOD;
		}
		int x, y, g = exgcd(a[i][i], MOD, x, y);
		ans[i] = (ans[i] / g * x % MOD + MOD) % MOD;
	}
	return 1;
}

void solve() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (!n && !m) break;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= m; ++i) {
			int k;
			scanf("%d%s", &k, s);
			a[i][n + 1] -= getWeek();
			scanf("%s", s);
			a[i][n + 1] += getWeek() + 1;
			a[i][n + 1] = (a[i][n + 1] % MOD + MOD) % MOD;
			for (int j = 1; j <= k; ++j) {
				int type;
				scanf("%d", &type);
				++a[i][type];
				a[i][type] %= MOD;
			}
		}
		int rt = gauss();
		if (rt == 0) {
			puts("Inconsistent data.");
		} else if (rt == 2) {
			puts("Multiple solutions.");
		} else {
			for (int i = 1; i <= n; ++i) {
				if (i != 1) printf(" ");
				if (ans[i] < 3) ans[i] += MOD;
				printf("%d", ans[i]);
			}puts("");
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
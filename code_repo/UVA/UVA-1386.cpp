/*

题意：一个有n格的环，每格有数字，每次操作把一个格子里的数改为距离它d以内的格子的数的和再模m，求k次操作后环上的数字

解：
直接矩阵快速幂，一次乘法时间复杂度O(n^3)
发现这里矩阵是循环矩阵，所以乘法可优化为O(n^2)

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 500 + 5;
const int MAX_M = 30 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int n, m, d, k;

struct Matrix {
	LL a[MAX_N];
	
	Matrix() {
		memset(a, 0, sizeof(a));
	}
	
	Matrix operator*(const Matrix & b) {
		Matrix tmp;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				tmp.a[i] += a[j] * b.a[(j + n - i ) % n + 1];
				tmp.a[i] %= m;
			}
		}
		return tmp;
	}
};

Matrix matrixQPow(Matrix a, int b) {
	Matrix c;
	c.a[1] = 1;
	while (b) {
		if (b & 1) c = c * a;
		a = a * a;
		b >>= 1;
	}
	return c;
}

void solve() {
	while (~scanf("%d%d%d%d", &n, &m, &d, &k)) {
		Matrix a;
		for (int i = -d; i <= d; ++i) a.a[(i + n) % n + 1] = 1;
		a = matrixQPow(a, k);
		Matrix ans;
		for (int i = 1; i <= n; ++i) scanf("%lld", &ans.a[i]);
		ans = ans * a;
		for (int i = 1; i <= n; ++i) printf("%lld%c", ans.a[i], i == n ? '\n' : ' ');
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
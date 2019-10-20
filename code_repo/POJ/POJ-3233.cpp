/*

题意：给一个n阶矩阵A，求A+A^2+...+A^k，取模m

解：
矩阵快速幂
用二分幂解决，和等比数列求和的二分方法一样
具体见：https://blog.csdn.net/kalilili/article/details/44926947
qwq

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 30 + 5;
const int MAX_M = 30 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int T, N, K, m;

struct Matrix {
	int a[MAX_N][MAX_N];
	int n;
	
	Matrix(int n = 0):n(n) {
		memset(a, 0, sizeof(a));
	}
	
	Matrix operator+(const Matrix & b) {
		Matrix tmp(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				tmp.a[i][j] += a[i][j];
				tmp.a[i][j] %= m;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				tmp.a[i][j] += b.a[i][j];
				tmp.a[i][j] %= m;
			}
		}
		return tmp;
	}
	
	Matrix operator*(const Matrix & b) {
		Matrix tmp(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					tmp.a[i][j] += a[i][k] * b.a[k][j];
					tmp.a[i][j] %= m;
				}
			}
		}
		return tmp;
	}
} A, ans;

Matrix matrixQPow(Matrix a, int b) {
	Matrix e(N);
	memset(e.a, 0, sizeof(e.a));
	for (int i = 1; i <= N; ++i) e.a[i][i] = 1;
	while (b) {
		if (b & 1) e = e * a;
		a = a * a;
		b >>= 1;
	}
	return e;
}

Matrix getE() {
	Matrix e(N);
	memset(e.a, 0, sizeof(e.a));
	for (int i = 1; i <= N; ++i) e.a[i][i] = 1;
	return e;
}

Matrix sum(int k) {
	if (k == 1) return A;
	Matrix s = sum(k / 2);
	if (k & 1) {
		Matrix tmp = matrixQPow(A, k / 2 + 1);
		return ((getE() + tmp) * s) + tmp;
	} else {
		return (getE() + matrixQPow(A, k / 2)) * s;
	}
}

void solve() {
	scanf("%d%d%d", &N, &K, &m);
	A.n = N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A.a[i][j]);
			A.a[i][j] %= m;
		}
	}
	ans = sum(K);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%d%c", ans.a[i][j], j == N ? '\n' : ' ');
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
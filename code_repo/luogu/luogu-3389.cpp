/*

高斯消元板子 qwq
系数矩阵a 增广矩阵A
无解 r(a)<r(A)
唯一 r(a)=r(A)=n
无穷 r(a)=r(A)<n
自由元看某一列是否全是0

*/

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

int n;
double a[MAX_N][MAX_N], ans[MAX_N];

//0-无解 1-唯一 2-无穷
int gauss() {
	int rank = n, now = 1;
	for (int i = 1; i <= n; ++i) {
		int r = now;
		for (int j = now + 1; j <= n; ++j) {
			if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
		}
		if (fabs(a[r][i]) < EPS) {
			--rank;
			continue;
		}
		if (r != now) swap(a[now], a[r]);
		double div = a[now][i];
		for (int j = i; j <= n + 1; ++j) {
			a[now][j] /= div;
		}
		for (int j = now + 1; j <= n; ++j) {
			div = a[j][i];
			for (int k = i; k <= n + 1; ++k) {
				a[j][k] -= div * a[now][k];
			}
		}
		++now;
	}
	for (int i = rank + 1; i <= n; ++i) {
		if (fabs(a[i][n + 1]) > EPS) return 0; 
	}
	if (rank < n) {
		return 2;
	}
	for (int i = n; i >= 1; --i) {
		ans[i] = a[i][n + 1];
		for (int j = i + 1; j <= n; ++j) {
			ans[i] -= ans[j] * a[i][j];
		}
	}
	return 1;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			scanf("%lf", &a[i][j]);
		}
	}
	int stt = gauss();
	if(stt == 1)for (int i = 1; i <= n; ++i) printf("%.2f\n", ans[i]);
	else if (stt == 2) printf("No Solution");
}

int main() {
//	freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
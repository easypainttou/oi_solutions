/*

题意：m个学生，n个不同的座位围绕圆桌，每2个学生之间至少隔k个空座位，有多少种不同的方法

解：C(n-m*k-1,m-1)*n/m

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1e6 + 10;
const int MOD = 1e9 + 7;

LL fac[MAX_N], T, n, m, k, ans;

void init() {
	fac[0] = 1;
	for (LL i = 1; i <= MAX_N - 10; i++) fac[i] = fac[i-1] * i % MOD;
}

LL qpow(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

LL C(LL a, LL b) {
	if (a < b) return 0;
	LL ans = fac[a] * qpow(fac[b], MOD - 2) % MOD * qpow(fac[a - b], MOD - 2) % MOD;
	return ans;
}

void solve() {
	init();
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		if (m == 1) {
			printf("%d\n", n);
			continue;
		}
		ans = C(n - m * k - 1, m - 1) * n % MOD * qpow(m, MOD - 2) % MOD;
		printf("%lld\n", ans);
	}
}

int main() {
	solve();
	return 0;
}
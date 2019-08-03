/*

扩展中国剩余定理 板子题

*/

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 400 + 10;
const int MAX_M = 40000 + 10;
const int INF = 0x3f3f3f3f;

LL n, m[10], a[10];

LL exgcd(LL a, LL b, LL& x, LL& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	LL g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

LL excrt() {
	LL M = m[1], X = a[1];
	for (LL i = 2; i <= n; i++) {
		LL c = ((a[i] - X) % m[i] +m[i]) % m[i], x, y, g = exgcd(M, m[i], x, y);
		if (c % g) {
			return -1;
		}
		LL p = m[i] / g;
		x = x * c / g % p;
		X += x * M;
		M *= p;
		X = (X % M + M) % M;
	}
	if (X == 0) X += M; //wa点，输出最小正整数，没有这个就是最小非负整数
	return X;
}

void solve() {
	LL T;
	scanf("%lld", &T);
	for (LL kase = 1; kase <= T; kase++) {
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) scanf("%d", m + i);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("Case %lld: %lld\n", kase, excrt());
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
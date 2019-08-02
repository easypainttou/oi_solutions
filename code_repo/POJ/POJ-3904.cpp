/*

题意：n个数，选4个，求4个数互质的方案数

解：先算c(n,4)，然后减去gcd不为1的选法，gcd不为1的选法使用容斥原理计算

*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int MAX_N = 1e4 + 5;

LL n, id, cnt[MAX_N], tot, p[MAX_N], ans, maxn, pCnt[MAX_N];

void getFactor(LL x) {
	tot = 0;
	for (LL i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			p[++tot] = i;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) p[++tot] = x;
	for (LL i = 1; i < 1 << tot; i++) {
		LL tmp = i, num = 1, facCnt = 0;
		for (LL j = 0; tmp ; j++, tmp >>= 1) {
			if (tmp & 1) {
				num *= p[j + 1];
				facCnt++;
			}
		}
		cnt[num]++;
		pCnt[num] = facCnt;
	}
}

LL cn4(LL x) {
	return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

inline void init() {
	memset(cnt, 0, sizeof(cnt));
	memset(pCnt, 0, sizeof(pCnt));
	maxn = 0;
}

void solve() {
	while(~scanf("%lld", &n)){
		init();
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &id);
			maxn = max(maxn, id);
			getFactor(id);
		}
		ans = cn4(n);
		for (LL i = 2; i <= maxn; i++) {
			if (pCnt[i] & 1) {
				ans -= cn4(cnt[i]);
			} else {
				ans += cn4(cnt[i]);
			}
		}
		printf("%lld\n", ans);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
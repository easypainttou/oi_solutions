/*

qwq
参考了tutorial
https://codeforces.com/blog/entry/67598

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAX_N = 3e6 + 20;

LL n, b, cnt[MAX_N], mnDiv[MAX_N], id[MAX_N], mx;
vector<LL> ans;

void init() {
	LL tot = 0;
	for (LL i = 1; i <= MAX_N - 5; i++) mnDiv[i] = i;
	for (LL i = 2; i <= MAX_N - 5; i++) {
		if (i != mnDiv[i]) {
			continue;
		}
		id[i] = ++tot;
		for (LL j = (LL)i * i; j <= MAX_N - 5; j += i) {
			mnDiv[j] = min(mnDiv[j], i);
		}
	}
}

void solve() {
	scanf("%I64d", &n);
	for (LL i = 1; i <= n << 1; i++) scanf("%I64d", &b), mx = max(mx, b), cnt[b]++;
	init();
	for (LL i = mx; i >= 1; i--) {
		while (cnt[i] > 0) {
			if (mnDiv[i] == i) {
				cnt[id[i]]--;
				ans.push_back(id[i]);
			} else {
				cnt[i / mnDiv[i]]--;
				ans.push_back(i);
			}
			cnt[i]--;
		}
	}
	for (LL i = 0; i <ans.size(); i++) {
		if (i) printf(" ");
		printf("%I64d", ans[i]);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
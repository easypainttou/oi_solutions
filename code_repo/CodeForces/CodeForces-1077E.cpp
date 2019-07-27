/*

题意：n个问题，第i个问题主题为ai。在连续几天比赛，要求每场的问题是同一主题，每场主题不同，第i+1场的问题是第i场的问题的2倍，总问题数最多，求最多问题数

解：
假设有k天，每一场问题数就是a,a*2^1,a*2^2...a*2^(k-1)
用数组存放每种问题数量，排序，枚举所有可能的a，每次从问题数量最大的主题向前考虑，看最多能连续几天，然后算出最多问题数，和之前的结果取大

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

typedef long long LL;

using namespace std;

const int MAX_N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

LL n, cnt[MAX_N], tot, ans;
map<LL, LL> mp;

void solve() {
	scanf("%I64d", &n);
	for (int i = 1; i <= n; i++) {
		LL a;
		scanf("%I64d", &a);
		if (!mp[a]) mp[a] = ++tot;
		cnt[mp[a]]++;
	}
	sort(cnt + 1, cnt + tot + 1);
	for (LL i = 1; i <= cnt[tot]; i++) {
		LL cur = tot, k = min(tot, 20LL), len = 0;
		while (cur >= 1 && k >= 0) {
			while (k >= 0 && cnt[cur] < i * (1 << k)) k--;
			if (k >= 0) len++, k--, cur--;
		}
		ans = max(ans, i * ((1 << len) - 1));
	}
	printf("%I64d", ans);
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
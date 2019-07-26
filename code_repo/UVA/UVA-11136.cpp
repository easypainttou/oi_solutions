/*

水题 multiset模拟
qwq

*/

#include <cstdio>
#include <set>
#include <iostream>

typedef long long LL;

using namespace std;

const int MAX_N = 1e7 + 5;

int n, k, b, mn, mx;
LL ans;
multiset<int> mtst;
multiset<int>::iterator it;

void solve() {
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		mtst.clear();
		ans = 0;
		while (n--) {
			scanf("%d", &k);
			while (k--) {
				scanf("%d", &b);
				mtst.insert(b);
			}
			it = mtst.begin();
			mn = *it;
			mtst.erase(it);
			it = mtst.end();
			mx = *(--it);
			mtst.erase(it);
			ans += (LL)mx - mn;
		}
		printf("%lld\n", ans);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
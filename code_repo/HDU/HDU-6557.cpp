/*

题意：n个ki，分成2堆，使每一堆1/2^ki的和大于等于1/2

解：参考dalao的 使用了并查集 优先队列。。。

*/

#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> pr;

const int MAX_N = 1e5 + 5;

int T, n, fa[MAX_N];
priority_queue< pr > Q;

int findFa(int x) {
	if (fa[x] == x) return x;
	return fa[x] = findFa(fa[x]);
}

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++) {
		while (Q.size()) Q.pop();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int k;
			scanf("%d", &k);
			Q.push(make_pair(k, i));
			fa[i] = i;
		}
		while (Q.size() && Q.top().first != 1) {
			pr k1 = Q.top(); Q.pop();
			if (Q.empty()) break;
			if (Q.top().first != k1.first)continue;
			pr k2 = Q.top(); Q.pop();
			int f1 = findFa(k1.second), f2 = findFa(k2.second);
			fa[f1] = f2;
			Q.push(make_pair(k1.first - 1, f2));
		}
		printf("Case %d: ", kase);
		if (Q.size() >= 2) {
			puts("YES");
			for (int i = 1; i <= n; i++) printf("%d", findFa(i) == Q.top().second ? 1 : 0);
			puts("");
		} else {
			puts("NO");
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
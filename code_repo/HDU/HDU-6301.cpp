/*

题意：n个正整数的数组，要求li，ri区间的数互不相同，求字典序最小的数组

解：参考dalao的qwq，预处理出pre，然后可以O(n)地遍历，使用set以取到最小值
不易想到qwq。。。不太理解

*/

#include <cstdio>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

int T, n, m, pre[MAX_N], ans[MAX_N];
set<int> st;

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) res = res * 10 +ch -'0';
	return res * f;
}

void solve() {
	T = read();
	while (T--) {
		n = read(), m = read();
		st.clear();
		for (int i = 1; i <= n; i++) {
			pre[i] = i;
			st.insert(i);
		}
		for (int i = 1; i <= m; i++) {
			int l, r;
			l = read(), r = read();
			pre[r] = min(pre[r], l);
		}
		for (int i = n - 1; i >= 1; i--) {
			pre[i] = min(pre[i], pre[i + 1]);
		}
		int pos = 1;
		for (int i = 1; i <= n; i++) {
			while (pos < pre[i]) st.insert(ans[pos++]);
			ans[i] = *st.begin();
			st.erase(*st.begin());
		}
		for (int i = 1; i <= n; i++) {
			if (i != 1) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
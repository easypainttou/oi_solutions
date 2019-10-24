/*

题意：对一个长度为n的数组a维护以下操作：1.在数组的末尾添加一个数x，数组的长度n自增1。2.给出查询区间[l,r]和一个值k，求l<=p<=r 时，k ^ ap ^ ... ^ an的最大值。

解：可持久化trie板子
记ai前缀异或和为si，查询的值等价于s(p-1) ^ sn ^ k的最大值，sn ^ k是定值，相当于查询si在[l-1,r-1]的最大值
所以把si加入trie，前缀trie相减得到区间

*/

#include <cstdio>
#include <iostream>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

typedef long long LL;

const int MAX_N = 6e5 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

struct Trie {
	int cnt, T[MAX_N], sum[MAX_N * 30], ch[MAX_N * 30][2];
	
	void insert(int now, int lst, int k) {
		for (int i = 29; i >= 0; --i) {
			sum[now] = sum[lst] + 1;
			int c = k >> i & 1;
			if (!ch[now][c]) ch[now][c] = ++cnt;
			ch[now][c ^ 1] = ch[lst][c ^ 1];
			now = ch[now][c];
			lst = ch[lst][c];
		}
		sum[now] = sum[lst] + 1;
	}
	
	int query(int u, int v, int k) {
		int res = 0;
		for (int i = 29; i >= 0; --i) {
			int c = k >> i & 1, x;
			if (sum[ch[v][c ^ 1]] - sum[ch[u][c ^ 1]]) x = c ^ 1, res += 1 << i;
			else x = c;
			u = ch[u][x];
			v = ch[v][x];
		}
		return res;
	}
} trie;

int n, m, s[MAX_N];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

void solve() {
	n = read(), m = read(); ++n;
	trie.insert(trie.T[1] = ++trie.cnt, 0, 0);
	inc(i, 2, n) {
		int a = read();
		s[i] = s[i - 1] ^ a;
		trie.insert(trie.T[i] = ++trie.cnt, trie.T[i - 1], s[i]);
	}
	inc(i, 1, m) {
		char op[2];
		scanf("%s", op);
		if (op[0] == 'A') {
			int x = read();
			++n;
			s[n] = s[n - 1] ^ x;
			trie.insert(trie.T[n] = ++trie.cnt, trie.T[n - 1], s[n]);
		} else {
			int L = read(), R = read(), x = read();
			printf("%d\n", trie.query(trie.T[max(0, L - 1)], trie.T[R], s[n] ^ x));
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
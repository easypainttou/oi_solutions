/*

题意：长度为n的字符串s，m个询问，每个询问给出x，y，len，判断s[x,x+len-1]和s[y,y+len-1]是否同构，同构指字符串a把字符一一映射到另一个字符后，和另一个字符串b相同

解：把字符串s对于每个字符做一次hash，然后对于查询直接查看2个子串的各个字符的hash排序后是否相同。。。
看代码qwq

*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAX_N = 2e5 + 5;
const int MAX_M = 26 + 5;
const LL MOD = 1e9 + 7;
const LL BASE = 13331;

int n, m;
LL p[MAX_N], hashV[MAX_M][MAX_N], hashX[MAX_M], hashY[MAX_M];
char s[MAX_N];

void solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	p[0] = 1;
	for (int i = 1; i <= n; i++) p[i] = p[i - 1] * BASE % MOD;
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			hashV[i][j] = (hashV[i][j - 1] * BASE % MOD + (s[j] - 'a' == i ? 1 : 0)) % MOD;
		}
	}
	while (m--) {
		int x, y, len;
		scanf("%d%d%d", &x, &y, &len);
		for (int i = 0; i < 26; i++) {
			hashX[i] = (hashV[i][x + len - 1] - hashV[i][x - 1] * p[len] % MOD + MOD) % MOD;
			hashY[i] = ((hashV[i][y + len - 1] - (hashV[i][y - 1] * p[len] % MOD)) % MOD + MOD) % MOD;
		}
		sort(hashX, hashX + 26);
		sort(hashY, hashY + 26);
		bool f = 1;
		for (int i = 0; i < 26; i++) {
			if (hashX[i] != hashY[i]) {
				f = 0;
				break;
			}
		}
		if (f) puts("YES");
		else puts("NO");
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
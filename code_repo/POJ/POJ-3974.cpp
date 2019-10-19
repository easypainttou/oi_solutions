/*

最长回文子串 板子题
使用manacher实现时间复杂度O(n)

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 5;

int len, r[MAX_N << 1];
char s1[MAX_N], s2[MAX_N << 1];

void build() {
	int tot = 0;
	s2[tot++] = '@';
	for (int i = 0; i < len; ++i) {
		s2[tot++] = '#', s2[tot++] = s1[i];
	}
	s2[tot++] = '#', s2[tot++] = 0;
	len = tot;
}

int manacher() {
	build();
	int res = 0, maxR = 0, pos = 0;
	for (int i = 1; i <len; ++i) {
		r[i] = i < maxR ? min(r[(pos << 1) - i], maxR - i + 1) : 1;
		while (s2[i - r[i]] == s2[i + r[i]]) ++r[i];
		if (i + r[i] - 1 > maxR) {
			maxR = i + r[i] - 1;
			pos = i;
		}
		res = max(res, r[i] - 1);
	}
	return res;
}

void solve() {
	int kase = 0;
	while (1) {
		scanf("%s", s1);
		len = strlen(s1);
		if (len >= 3 && s1[0] == 'E' && s1[1] == 'N' && s1[2] == 'D') break;
		++kase;
		printf("Case %d: %d\n", kase,  manacher());
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
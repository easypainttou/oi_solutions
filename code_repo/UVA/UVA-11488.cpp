/*

题意：n个01字符串，
对于一个子集，最长公共前缀的长度为prefix，子集大小number
求最大prefix*number

解：字典树板子qwq

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

const int MAX_N = 1e7 + 5;

int T, n, ans;
char str[205];

struct node {
	int cnt, dic[2];
};

struct trie {
	int tot;
	node nodes[MAX_N];
	
	void init() {
		tot = 1;
		memset(nodes, 0, sizeof(nodes));
	}
	
	void insert() {
		int now = 1, len = strlen(str + 1);
		for (int i = 1; i <= len; i++) {
			int ch = str[i]-'0';
			if (!nodes[now].dic[ch]) nodes[now].dic[ch] = ++tot;
			now = nodes[now].dic[ch];
			nodes[now].cnt++;
			ans = max(ans, nodes[now].cnt * i);
		}
	}
}trie1;

inline void init() {
	ans = 0;
	trie1.init();
}

void solve() {
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		while (n--) {
			scanf("%s", str + 1);
			trie1.insert();
		}
		printf("%d\n", ans);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
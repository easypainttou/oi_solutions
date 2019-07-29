/*

题意：一个有n个非负数的数组，m个查询，一个查询给一个x，数组中每个元素修改为它异或x，对于每个查询，求结果数组的mex

解：
将元素表示成二进制，最大的二进制位数为n，然后就只需要关注0~2^n-1范围内所有不在原始数组中的元素，每次在异或后的结果中取小就是答案
取小的方法可以使用01字典树

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAX_N = 1 << 19;
const int MAX_M = 3e6 + 5;

int n, m, cnt[MAX_N], x;

struct node {
	int x, dic[3];
};

struct trie {
	node nodes[MAX_M];
	int tot;
	
	void init() {
		tot = 1;
	}
	
	void insert(int k) {
		int now = 1;
		for (int i = 19; i >= 0 ; i--) {
			int ch = k >> i & 1;
			ch++;
			if (!nodes[now].dic[ch]) nodes[now].dic[ch] = ++tot;
			now = nodes[now].dic[ch];
		}
		nodes[now].x = k;
	}
	
	int find(int k) {
		int now = 1;
		for (int i = 19; i >= 0 ; i--) {
			int ch = k >> i & 1;
			ch++;
			if (nodes[now].dic[ch]) now = nodes[now].dic[ch];
			else now = nodes[now].dic[3 - ch];
		}
		return nodes[now].x;
	}
} trie1;

void solve() {
	trie1.init();
	scanf("%d%d", &n, &m);
	for (int a, i = 1; i <= n; i++) scanf("%d", &a), cnt[a]++;
	for (int i = 0; i < MAX_N; i++) {
		if (!cnt[i]) trie1.insert(i);
	}
	while (m--) {
		int tmp;
		scanf("%d", &tmp);
		x ^= tmp;
		printf("%d\n", trie1.find(x) ^ x);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
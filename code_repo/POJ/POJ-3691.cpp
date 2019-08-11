/*

题意：DNA是包含A、G、C、T的字符串，给出N个致病DNA片段和1个要修复的DNA，要求改变DNA中最少的字符使DNA不包含致病片段

解：ac自动机+dp  qwq
首先插入致病的字符串，在结束的结点做标记。构造fail时某个结点的fail指向的结点若是被标记的，这个结点也要被标记。获取答案时，定义dp[i][j]为考虑到DNA的第i个字符、在第j个结点上的最少修改次数。考虑转移方程，dp[i][dic[j][k]]=dp[i-1][j]+(s[i]==k?0:1)，dic[j][k]为j结点指向的字符k的结点的编号。初始时dp[0][0]=0，其它为无穷。答案为min(dp[len][j])

*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e3 +5;
const int MAX_M = 30;
const int INF = 0x3f3f3f3f;

int n;
char s[MAX_N];

inline int getIdx(const char & ch) {
	if (ch == 'A') return 0;
	if (ch == 'G') return 1;
	if (ch == 'C') return 2;
	if (ch == 'T') return 3;
}

struct AC {
	int tot, dic[MAX_N][4], fail[MAX_N], bk[MAX_N], dp[MAX_N][MAX_N];
	queue<int> Q;
	
	void init() {
		tot = 0;
		newNode();
	}
	
	int newNode() {
		inc(i, 0, 3) dic[tot][i] = 0;
		fail[tot] = bk[tot++] = 0;
		return tot - 1;
	}
	
	void insert() {
		int len = strlen(s), now = 0;
		inc(i, 0, len - 1) {
			int ch = getIdx(s[i]);
			if (!dic[now][ch]) dic[now][ch] = newNode();
			now = dic[now][ch];
		}
		bk[now] = 1;
	}
	
	void getFail() {
		while (Q.size()) Q.pop();
		inc(i, 0, 3) if (dic[0][i]) fail[dic[0][i]] = 0, Q.push(dic[0][i]);
		while (Q.size()) {
			int now = Q.front(); Q.pop();
			inc(i, 0, 3) {
				if (dic[now][i]) {
					fail[dic[now][i]] = dic[fail[now]][i];
					Q.push(dic[now][i]);
					bk[dic[now][i]] |= bk[fail[dic[now][i]]]; //关键
				} else {
					dic[now][i] = dic[fail[now]][i];
				}
			}
		}
	}
	
	int getAns() {
		int res = INF, len = strlen(s + 1);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		inc(i, 1, len) {
			inc(j, 0, tot - 1) {
				if (dp[i - 1][j] >= INF) continue;
				inc(k, 0, 3) {
					if (bk[dic[j][k]]) continue;
					dp[i][dic[j][k]] = min(dp[i][dic[j][k]], dp[i - 1][j] + (getIdx(s[i]) == k ? 0 : 1));
				}
			}
		}
		inc(i, 0, tot - 1) res = min(res, dp[len][i]);
		if (res >= INF) res = -1;
		return res;
	}
} ac;

void solve() {
	int kase = 0;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		++kase;
		ac.init();
		inc(i, 1, n) {
			scanf("%s", s);
			ac.insert();
		}
		ac.getFail();
		scanf("%s", s + 1);
		printf("Case %d: %d\n", kase, ac.getAns());
	}
}

int main() {
	solve();
	return 0;
}
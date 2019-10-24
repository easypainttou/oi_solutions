/*

题意：长度为n的数组a，接下来每行有一条命令，命令有4种形式： 
(1) Add i j,i和j为正整数,表示第i个营地增加j个人（j不超过30） 
(2)Sub i j ,i和j为正整数,表示第i个营地减少j个人（j不超过30）; 
(3)Query i j ,i和j为正整数,i<=j，表示询问第i到第j个营地的总人数; 
(4)End 表示结束，这条命令在每组数据最后出现; 

解：
单点修改，加法
区间查询，求和
可用线段树/树状数组/分块
以下线段树

*/

#include <cstdio>

#define inc(i, a, b) for (int i = a; i <= b; ++i)
#define dec(i, a, b) for (int i = a; i >= b; --i)
#define lson (rt << 1)
#define rson (rt << 1 | 1)

using namespace std;

typedef long long LL;

const int MAX_N = 5e4 + 5;
const int MAX_M = 6e6 + 5;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

//seg
int sum[MAX_N << 2];

int T, n, a[MAX_N];
char s[10];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

inline void pushUp(int rt) {
	sum[rt] = sum[lson] + sum[rson];
}

void build(int rt, int L, int R) {
	if (L == R) {
		sum[rt] = a[L];
		return;
	}
	int mid = L + R >> 1;
	build(lson, L, mid), build(rson, mid + 1, R);
	pushUp(rt);
}

void update(int rt, int L, int R, int pos, int k) {
	if (L == R) {
		sum[rt] += k;
		return;
	}
	int mid = L + R >> 1;
	if (pos <= mid) update(lson, L, mid, pos, k);
	else if (pos > mid) update(rson, mid + 1, R, pos, k);
	pushUp(rt);
}

int query(int rt, int L, int R, int s, int t) {
	if (s <= L && R <= t) {
		return sum[rt];
	}
	int mid = L + R >> 1, res = 0;
	if (s <= mid) res += query(lson, L, mid, s, t);
	if (t > mid) res += query(rson, mid + 1, R, s, t);
	return res;
}

void solve() {
	T = read();
	for (int kase = 1; kase <= T; ++kase) {
		printf("Case %d:\n", kase);
		n = read();
		inc(i, 1, n) a[i] = read();
		build(1, 1, n);
		while (1) {
			int i, j;
			scanf("%s", s);
			if (s[0] == 'A') {
				i = read(), j = read();
				update(1, 1, n, i, j);
			} else if (s[0] == 'S') {
				i = read(), j = read();
				update(1, 1, n, i, -j);
			} else if (s[0] == 'Q') {
				i = read(), j = read();
				printf("%d\n", query(1, 1, n, i, j));
			} else break;
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
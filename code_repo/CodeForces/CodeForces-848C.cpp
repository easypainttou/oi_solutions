/*

题意：长度n的数组，数字在x在[L,R]内的值为数字x在其中最后一次出现的下标减去第一次出现的下标，给m次询问，每次3个整数a，b，c
a=1，第b个元素改为c
a=2，求[b,c]所有数字的值的和

解：https://www.luogu.org/problemnew/solution/CF848C

*/

#include <bits/stdc++.h>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 10;
const int MAX_M = 1e6 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
	int x, pre, v, op, id;
	Node(int x = 0, int pre = 0, int v = 0, int op = 0, int id = 0): x(x), pre(pre), v(v), op(op), id(id) {}
	
	bool operator<(const Node & a) {
		if (x == a.x) {
			return pre < a.pre;
		}
		return x < a.x;
	}
} Q[MAX_M];
int n, m, a[MAX_N], pre[MAX_N], nxt[MAX_N], tmp[MAX_N], tot;
LL c[MAX_N], size[MAX_M << 2];
set<int> st[MAX_N];
bool resQ[MAX_M];

int read() {
	int res = 0, f = 1;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) res = res * 10 + ch - '0';
	return res * f;
}

int lowbit(int x) {return x & (-x);}

void add(int x, int k) {for (; x <= n + 1; x += lowbit(x)) c[x] += k;}

LL query(int x) {LL res = 0; for (; x > 0; x -= lowbit(x)) res += c[x]; return res;}

void CDQ(int L, int R) {
	if (L == R) return;
	int mid = (L + R) >> 1;
	CDQ(L, mid), CDQ(mid + 1, R);
	sort(Q + L, Q + mid + 1) , sort(Q + mid + 1, Q + R + 1);
	int i = mid + 1, j = L;
	for (; i <= R; i++) {
		for (; j <= mid && Q[j].x <= Q[i].x; j++) {
			if (Q[j].op == 1) {
				add(Q[j].pre + 1, Q[j].v);
			}
		}
		if (Q[i].op == 2) {
			size[Q[i].id] += query(Q[i].pre + 1);
		}
	}
	for (i = L; i < j; i++) {
		add(Q[i].pre + 1, -Q[i].v);
	}
}

void solve() {
	n = read(), m = read();
	inc(i, 1, n) st[i].insert(0), st[i].insert(n + 1);
	inc(i, 1, n) {
		a[i] = read();
		pre[i] = tmp[a[i]];
		tmp[a[i]] = i;
		st[a[i]].insert(i);
		Q[++tot] = Node(i, pre[i], i - pre[i], 1, 0);
	}
	inc(i, 1, n) tmp[i] = n + 1;
	dec(i, n, 1) {
		nxt[i] = tmp[a[i]];
		tmp[a[i]] = i;
	}
	inc(i, 1, m) {
		int x = read(), y = read(), z = read();
		if (x == 1) {
			if (a[y] == z) continue;
			Q[++tot] = Node(y, pre[y], pre[y] - y, 1, 0);
			Q[++tot] = Node(nxt[y], y, y - nxt[y], 1, 0);
			Q[++tot] = Node(nxt[y], pre[y], nxt[y] - pre[y], 1, 0);
			pre[nxt[y]] = pre[y];
			nxt[pre[y]] = nxt[y];
			st[a[y]].erase(y);
			a[y] = z;
			st[z].insert(y);
			set<int>::iterator it = st[z].find(y);
			int p = *(--it), n = *(++(++it));
			nxt[p] = y;
			pre[n] = y;
			pre[y] = p, nxt[y] = n;
			Q[++tot] = Node(n, p, p - n, 1, 0);
			Q[++tot] = Node(n, pre[n], n - pre[n], 1, 0);
			Q[++tot] = Node(y, pre[y], y - pre[y], 1, 0);
		} else {
			resQ[i] = 1;
			Q[++tot] = Node(z, z, 0, 2, (i << 2) - 3);
			Q[++tot] = Node(z, y - 1, 0, 2, (i << 2) - 2);
			Q[++tot] = Node(y - 1, z, 0, 2, (i << 2) - 1);
			Q[++tot] = Node(y - 1, y - 1, 0, 2, (i << 2));
		}
	}
	CDQ(1, tot);
	inc(i, 1, m) {
		if (resQ[i]) printf("%I64d\n", size[(i << 2) - 3] - size[(i << 2) - 2] - size[(i << 2) - 1] + size[(i << 2)]);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
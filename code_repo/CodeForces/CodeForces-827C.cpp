/*

题意：给一个只包含A、T、G、C的字符串s，给q个事件，有2种事件
1 x c 把s[x]换成c
2 l r e 求s[l]...s[r]和eeee...相同字符的个数

解：只有4种字符，e的长度最长只有10，开10*10*4个树状数组，bit[a][b][c][x]中，x为s中第x个字符，e的长度为b，a为x%b（同一个b，a相同的就是对应e中的同一个位置），c为字符编号。。。具体看代码
qwq
剩余类的思想？

*/

#include <cstdio>
#include <cstring>
#include <algorithm>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 1e5 + 10;
const int MAX_M = 1e7 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

char s[MAX_N], tmp[15];
int q, n, bit[15][15][5][MAX_N];

inline int lowbit(int x) {return x & (-x);}

void add(int a, int b, int c, int x, int k) {
	while (x <= n) {
		bit[a][b][c][x] += k;
		x += lowbit(x);
	}
}

int query(int a, int b, int c, int x) {
	int res = 0;
	while (x > 0) {
		res += bit[a][b][c][x];
		x -= lowbit(x);
	}
	return res;
}

inline int getIdx(char ch) {
	if (ch == 'A') return 0;
	if (ch == 'T') return 1;
	if (ch == 'G') return 2;
	else return 3;
}

void solve() {
	scanf("%s%d", s + 1, &q);
	n = strlen(s + 1);
	inc(i, 1, n) {
		inc(j, 1, 10) {
			add(i % j, j, getIdx(s[i]), i, 1);
		}
	}
	while (q--) {
		int id;
		scanf("%d", &id);
		if (id == 1) {
			int x;
			scanf("%d%s", &x, tmp);
			inc(i, 1, 10) {
				add(x % i, i, getIdx(s[x]), x, -1);
				add(x % i, i, getIdx(tmp[0]), x, 1);
			}
			s[x] = tmp[0];
		} else {
			int l, r;
			scanf("%d%d%s", &l, &r, tmp + 1);
			int m = strlen(tmp + 1);
			int res = 0;
			inc(i, 1, m) {
				res += query((l + i - 1) % m, m, getIdx(tmp[i]), r) - query((l + i - 1) % m, m, getIdx(tmp[i]), l - 1);
			}
			printf("%d\n", res);
		}
	}
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    solve();
    return 0;
}
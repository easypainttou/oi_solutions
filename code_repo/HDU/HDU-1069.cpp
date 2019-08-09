/*

题意：n种长方体，每种有无穷多个，每种有三个维度为xi，yi，zi，可以旋转。要求选择一些，使下面的长方体的长和宽严格大于上面的一个，求最高高度

解：其实就是LIS。。。

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 200 + 5;

struct Block {
	int x, y, z;
	
	Block(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
	
	bool operator<(const Block & a) {
		if (x == a.x) {
			return y > a.y;
		}
		return x > a.x;
	}
} b[MAX_N];

int n, tot, dp[MAX_N], ans;

inline void addBlock(int x, int y, int z) {
	b[++tot] = Block(x, y, z);
}

void solve() {
	int kase = 0;
	while (1) {
		tot = ans = 0;
		scanf("%d", &n);
		if (!n) break;
		++kase;
		inc(i, 1, n) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (x == y && y == z) {
				addBlock(x, y, z);
			} else if (x == y && y != z) {
				addBlock(z, x, y);
				addBlock(x, z, y);
				addBlock(x, y, z);
			} else if (x != y && y == z) {
				addBlock(x, y, z);
				addBlock(y, x, z);
				addBlock(y, z, x);
			} else if (x != y && x == z) {
				addBlock(y, x, z);
				addBlock(x, y, z);
				addBlock(x, z, y);
			} else {
				addBlock(x, y, z);
				addBlock(x, z, y);
				addBlock(y, x, z);
				addBlock(y, z, x);
				addBlock(z, x, y);
				addBlock(z, y, x);
			}
		}
		sort(b + 1, b + tot + 1);
		inc(i, 1, tot) dp[i] = b[i].z;
		inc(i, 1, tot) {
			inc(j, 1, i - 1) {
				if (b[j].x > b[i].x && b[j].y > b[i].y) {
					dp[i] = max(dp[i], dp[j] + b[i].z);
				}
			}
		}
		inc(i, 1, tot) ans = max(ans, dp[i]);
		printf("Case %d: maximum height = %d\n", kase, ans);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
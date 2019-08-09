/*

题目描述不清楚，看了discuss。。。
http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=17605&messageid=1&deep=0

题意：有N张发票，要求每一张发票中每一类必须是A或B或C，一张发票每一类的总价值不超过600，一张发票总额不超过1000。选择一些满足要求的发票，这些发票总额不超过Q，求最大总额

解：题目没说，价值其实都是保留小数点后2位的小数。。。只要乘100后就是整数，所以做法就是先选出满足条件的发票，然后01背包

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

#define inc(i, a, b) for (int i = a; i <= b; i++)
#define dec(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

typedef long long LL;

const int MAX_N = 3e6 + 5;

double Q;
int q, n, v[MAX_N], dp[MAX_N];

void solve() {
	while (1) {
		scanf("%lf%d", &Q, &n);
		if (!n) break;
		q = Q * 100;
		inc(i, 1, n) {
			bool f = 0;
			int m;
			char tp;
			double x, a = 0, b = 0, c = 0;
			scanf("%d", &m);
			inc(j, 1, m) {
				getchar();
				scanf("%c:%lf", &tp, &x);
				int tmp = 100 * x;
				if (tp == 'A') {
					a += tmp;
				} else if (tp == 'B') {
					b += tmp;
				} else if (tp == 'C') {
					c += tmp;
				} else {
					f = 1;
				} 
			}
			if (!f && a + b + c <= 100000 && a <= 60000 && b <= 60000 && c <= 60000) {
				v[i] = a + b + c;
			} else {
				v[i] = q + 1;
			}
		}
		memset(dp, 0, sizeof(dp));
		inc(i, 1, n) {
			dec(j, q, v[i]) {
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
			}
		}
		printf("%.2f\n", dp[q] / 100.0);
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	solve();
	return 0;
}
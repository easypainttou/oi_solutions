/*

题意：迷宫有n个门，第i个门xi时间回到迷宫，或xi时间到迷宫外，每次等概率选一个，求到迷宫外的期望的时间

解：
设有m个门可以到迷宫外，到外面的期望为E
E=能到外面的x的和/n+(回到迷宫的x的和+(n-m)*E)/n
得到 E=x的和/m

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAX_N=1e5+10;
const int MAX_M=200+10;
const int inf=0x3f3f3f3f;

int T, n, m, sum;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase) {
		sum = m = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			if (x > 0) sum += x, ++m;
			else sum -= x;
		}
		printf("Case %d: ", kase);
		if (m) {
			int g = gcd(sum, m);
			printf("%d/%d\n", sum / g, m / g);
		} else {
			puts("inf");
		}
	}
}

int main(){
//	ios::sync_with_stdio(false);
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
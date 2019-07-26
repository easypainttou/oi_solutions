/*

题意：
一个f(x)三种指令
for n：循环
end：for n和end之间的指令执行n次
add：x加1
返回x
判断f(0)是否超过2^32-1，若没有输出x，否则OVERFLOW!!!

解：使用栈模拟。。。
然而一直WA
参考了tutorial
qwq

*/

#include <cstdio>
#include <stack>

typedef long long LL;

using namespace std;

const LL INF = 1LL << 32;

char str[10];
int n;
LL sum;
stack<LL> stk;

void solve() {
	scanf("%d", &n);
	stk.push(1);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		if (str[0] == 'f') {
			int x;
			scanf("%d", &x);
			stk.push(min(INF, stk.top() * x));
		} else if (str[0] == 'e') {
			stk.pop();
		} else {
			sum += stk.top();
		}
	}
	if (sum >= INF) puts("OVERFLOW!!!");
	else printf("%I64d\n", sum);
}

int main() {
	//freopen("in.txt", "r", stdin);
	solve();
	return 0;
}
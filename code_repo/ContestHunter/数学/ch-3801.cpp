/*
如果选择了区间L到R
1. L=R，概率是1/n^2
2. L<R，概率是2/n^2

为了简化，考虑到题目中的自然数在31位内，位之间没有影响
所以这里从低位到高位，计算每一个数（j）某一位（i）的贡献

1. L=R=j，如果j的i位为1，那么对于xor和，and和，or和的期望都有(1<<i)/n^2的贡献
2. 任意L，L<R=j，对于
xor ，以1为分割点（因为遇到1会取反，也就是说以j为右端点的区间，按照xor和的不同，可以分成xor和为0的分块和1的分块），记录2个变量，c1（和j邻近的那种分块的对应的分块的总长度）、c2（另一种的总长度）
and ，记录变量last0（j之前最后一个0的位置）
or ，记录变量last1（j之前最后一个1的位置）
然后期望的求法看代码...qwq
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=1e5+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int n,a[MAXN];
double ans[3];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=0;i<31;i++){
		int lst1=0,lst0=0,c1=0,c2=0;
		double e=(1<<i)*1.0/n/n;
		for(int j=1;j<=n;j++){
			if(a[j]>>i&1)ans[0]+=e,ans[1]+=e,ans[2]+=e; //累加L=R=j时的期望
			if(a[j]>>i&1){ //累加L<R=j时的期望
				ans[0]+=2.0*e*c1;
				ans[1]+=2.0*e*(j-lst0-1);
				ans[2]+=2.0*e*(j-1);
				++c1,swap(c1,c2),lst1=j;
			}else{
				ans[0]+=2.0*e*c2;
				ans[2]+=2.0*e*lst1;
				++c1;
				lst0=j;
			}
		}
	}
	printf("%.3lf %.3lf %.3lf",ans[0],ans[1],ans[2]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
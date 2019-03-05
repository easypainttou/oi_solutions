/*
n盘3塔
设d[n]表示解n盘3塔问题的最少步数
d[n]=2*d[n−1]+1
含义:前n−1个盘在3塔模式下从A到B，第n个盘在2塔模式下从A到C，n−1个盘在3塔模式下从B到C

n盘4塔
设f[n]表示解n盘4塔问题的最小步数
f[n]=min(2*f[i]+d[n−i])(1<=i<=n-1)
含义:前i个盘在4塔模式下从A到B，n−i个盘子在3塔模式下从A到D，i个盘子在4塔模式下从B到D

n盘m塔(m>4)
f[n,m]=min(2*f[i,m]+f[n−i,m−1])(1<=i<=n-1)
复杂度:O(n^2*m)
*/
#include<bits/stdc++.h>
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef set<int>::iterator it;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;
const int maxm=2e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;
const double pi=acos(-1);

int f[5][15];

void solve(){
	memset(f,0x3f,sizeof(f));
	f[3][0]=0;
	for(int i=1;i<=12;i++){
		f[3][i]=2*f[3][i-1]+1;
	}
	
	f[4][1]=1;
	for(int i=2;i<=12;i++){
		for(int j=1;j<i;j++){
			f[4][i]=min(f[4][i],2*f[4][j]+f[3][i-j]);
		}
	}
	for(int i=1;i<=12;i++)printf("%d\n",f[4][i]);
	
}
 
int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
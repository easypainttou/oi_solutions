/*
...剪枝很多qwq
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

int n,m,ans,bS,minS[25],minV[25];

inline int calV(int r,int h){
	return r*r*h;
}

void dfs(int r,int h,int step,int remain,int sz){
	if(step==1)bS=r*r;
	if(2*remain/r+sz+bS>ans)return; //最优性剪枝qwq 没有这个就T
	if(sz+minS[m-step]+bS>ans||minV[m-step]>remain)return;
	if(step>=1&&bS+sz>ans)return;
	if(step==m){
		if(remain==0){
			int ss=bS+sz;
			ans=min(ans,ss);
		}
		return;
	}
	int rmax=min(r-1,int(sqrt(remain)));
	for(int i=rmax;i>=m-step;i--){
		int hmax=min(h-1,remain/(i*i));
		for(int j=hmax;j>=m-step;j--){
			int v=calV(i,j);
			if(v<=remain){
				dfs(i,j,step+1,remain-v,sz+2*i*j);
			}
		}
	}
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)minS[i]=minS[i-1]+2*i*i,minV[i]=minV[i-1]+i*i*i;
	ans=inf,dfs(sqrt(n)+1,n+1,0,n,0);
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
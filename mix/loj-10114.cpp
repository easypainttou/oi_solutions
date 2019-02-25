/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=2e4+5;
const int maxm=4e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,maxnum,c[maxm],id[maxn],x[maxn],y[maxn],bk[maxn];

bool cmp(int a,int b){
	if(x[a]==x[b])return y[a]<y[b];
	return x[a]<x[b];
}

inline int lowbit(int x){return x&(-x);}

void add(int x){
	while(x<=maxnum){
		++c[x];
		x+=lowbit(x);
	}
}

int query(int x){
	int ans=0;
	while(x>=1){
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i),id[i]=i,++y[i],maxnum=max(maxnum,y[i]);
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++){
		int p=id[i];
		bk[query(y[p])]++;
		add(y[p]);
	}
	for(int i=0;i<=n-1;i++)printf("%d\n",bk[i]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
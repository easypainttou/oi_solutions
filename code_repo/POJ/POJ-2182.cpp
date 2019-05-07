/*
可以
暴力 O(n^2)
二分 O(n*(logn)^2)
倍增 利用树状数组的性质 O(nlogn)
*/
#include<cstdio>

using namespace std;

typedef long long ll;

const int MAXN=8e3+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int n,c[MAXN],pre[MAXN],ord[MAXN],lg[MAXN];

inline int lowbit(int x){return x&(-x);}

void add(int p,int k){
	while(p<=n){
		c[p]+=k;
		p+=lowbit(p);
	}
}

int query(int p){
	int res=0;
	while(p>0){
		res+=c[p];
		p-=lowbit(p);
	}
	return res;
}

void solve(){
	scanf("%d",&n);
	lg[0]=-1;
	for(int i=1;i<=n;i++)add(i,1),lg[i]=lg[i>>1]+1;
	for(int i=2;i<=n;i++)scanf("%d",pre+i);
	for(int i=n;i>=1;i--){
		int st=0,sum=0;		
		for(int j=lg[n];j>=0;j--){
			if(st+(1<<j)<=n&&sum+c[st+(1<<j)]<=pre[i]){
				st+=1<<j;
				sum+=c[st];
			}
		}
		ord[i]=st+1;
		add(st+1,-1);
	}
	for(int i=1;i<=n;i++)printf("%d\n",ord[i]);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
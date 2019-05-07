/*
线段树 扫描线 板子题
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
#define LS (rt<<1)
#define RS (rt<<1|1)
using namespace std;
typedef long long ll;

const int MAXN=200+5;
const int INF=0x3f3f3f3f;

struct line{
	double y,x1,x2;
	int k;
	line(double y=0,double x1=0,double x2=0,int k=0):y(y),x1(x1),x2(x2),k(k){}
}ls[MAXN];

bool operator<(const line&a,const line &b){
	return a.y<b.y;
}

int n,tot,flag[MAXN<<2];
double ans,preX[MAXN],g[MAXN<<2];
map<double,int>newX;

inline void pushUp(int rt,int L,int R){
	if(flag[rt]>0){
		g[rt]=preX[R+1]-preX[L];
	}else if(R==L){
		g[rt]=0;
	}else{
		g[rt]=g[LS]+g[RS];
	}
}

void update(int rt,int L,int R,int s,int t,int k){
	if(s<=L&&R<=t){
		flag[rt]+=k;
		pushUp(rt,L,R);
		return;
	}
	int mid=(L+R)>>1;
	if(s<=mid)update(LS,L,mid,s,t,k);
	if(t>mid)update(RS,mid+1,R,s,t,k);
	pushUp(rt,L,R);
}


void solve(){
	int kase=0;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		++kase;
		memset(flag,0,sizeof(flag));
		memset(g,0,sizeof(g));
		ans=0;
		newX.clear();
		double x1,y1,x2,y2;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			ls[(i<<1)-1]=line(y1,x1,x2,1);
			ls[i<<1]=line(y2,x1,x2,-1);
			preX[(i<<1)-1]=x1;
			preX[i<<1]=x2;
		}
		sort(ls+1,ls+(n<<1)+1);
		sort(preX+1,preX+(n<<1)+1);
		tot=unique(preX+1,preX+(n<<1)+1)-preX-1;
		for(int i=1;i<=tot;i++)newX[preX[i]]=i;
		for(int i=1;i<(n<<1);i++){
			update(1,1,tot-1,newX[ls[i].x1],newX[ls[i].x2]-1,ls[i].k);
			ans+=g[1]*(ls[i+1].y-ls[i].y);
		}
		printf("Test case #%d\nTotal explored area: %.2f\n\n",kase,ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 
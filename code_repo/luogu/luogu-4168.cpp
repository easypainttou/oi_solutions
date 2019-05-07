/*
一种做法...
O(N^(5/3))
*/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define LS (rt<<1)
#define RS (rt<<1|1)
using namespace std;
typedef long long ll;

const int N=4e4+10;
const int M=40;
const int INF=0x3f3f3f3f;

int n,m,T,len,a[N],tot,preA[N],newA[N],st[M],en[M],pos[N],cnt[M][M][N],maxCnt[M][M],maxNum[M][M],ccnt,nnum,ans;

inline void init(){
	T=(int)pow(n*1.0,1.0/3);
	if(T)len=n/T;
	
	for(int i=1;i<=T;i++)st[i]=(i-1)*len+1,en[i]=i*len; //i<=T 少了个=，然后一直TLE，qwq
	if(en[T]<n)++T,st[T]=en[T-1]+1,en[T]=n;
	
	for(int i=1;i<=T;i++)for(int j=st[i];j<=en[i];j++)pos[j]=i;
	
	sort(preA+1,preA+n+1);
	tot=unique(preA+1,preA+n+1)-preA-1;
	for(int i=1;i<=n;i++)newA[i]=lower_bound(preA+1,preA+tot+1,a[i])-preA;
		
	for(int i=1;i<=T;i++)for(int j=1;j<=T;j++){
		for(int k=st[i];k<=en[j];k++)++cnt[i][j][newA[k]];
		
		for(int k=1;k<=tot;k++)
			if(cnt[i][j][k]>maxCnt[i][j]||(cnt[i][j][k]==maxCnt[i][j]&&k<maxNum[i][j])){
				maxCnt[i][j]=cnt[i][j][k];
				maxNum[i][j]=k;
			}
	}
}

inline void update(const int &i,const int &j,const int &k){
	int &id=newA[k];
	++cnt[i][j][id];
	if(cnt[i][j][id]>ccnt||(cnt[i][j][id]==ccnt&&id<nnum)){
		ccnt=cnt[i][j][id];
		nnum=id;
	}
}

int query(int L,int R){
	if(L>R)swap(L,R);
	int lPos,rPos;
	if(pos[L]+1<=pos[R]-1)lPos=pos[L]+1,rPos=pos[R]-1;
	else lPos=rPos=0;
	
	ccnt=maxCnt[lPos][rPos];
	nnum=maxNum[lPos][rPos];
	
	if(pos[L]==pos[R]){
		for(int i=L;i<=R;i++)update(lPos,rPos,i);
		for(int i=L;i<=R;i++)--cnt[lPos][rPos][newA[i]];
	}else{
		for(int i=L;i<=en[pos[L]];i++)update(lPos,rPos,i);
		for(int i=st[pos[R]];i<=R;i++)update(lPos,rPos,i);
		for(int i=L;i<=en[pos[L]];i++)--cnt[lPos][rPos][newA[i]];
		for(int i=st[pos[R]];i<=R;i++)--cnt[lPos][rPos][newA[i]];
	}
	return preA[nnum];
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i),preA[i]=a[i];
	init();
	while(m--){
		int l0,r0;
		scanf("%d%d",&l0,&r0);
		ans=query((l0+ans-1)%n+1,(r0+ans-1)%n+1);
		printf("%d\n",ans);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
} 
/*
...
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=2e5+10;
const int MAXM=30;
const int M=1e6+5;

int last[(M<<1)+10],n,m,a[MAXN],s[MAXN],f[MAXN],st[MAXN][MAXM],lg[MAXN];

int read(){
	int res=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())res=res*10+ch-'0';
	return res*f;
}

inline void init(){
	lg[0]=-1;
	for(int i=1;i<=n;i++){
		s[i]=max(s[i-1],last[a[i]+M]+1);
		f[i]=i-s[i]+1;
		last[a[i]+M]=i;
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;i++)st[i][0]=f[i];
	for(int i=1;1<<i<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
}

inline int getMax(int Li,int Ri){
	if(s[Li]>=Li){
		int z=lg[Ri-Li+1];
		return max(st[Li][z],st[Ri-(1<<z)+1][z]);
	}
	if(s[Ri]<Li){
		return Ri-Li+1;
	}
	int L=Li,R=Ri,pos;
	while(L<=R){
		int mid=(L+R)>>1;
		if(s[mid]>=Li)pos=mid,R=mid-1;
		else L=mid+1;
	}
	int z=lg[Ri-pos+1];
	return max(pos-Li,max(st[pos][z],st[Ri-(1<<z)+1][z]));
}

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)a[i]=read();
	init();
	for(int i=1;i<=m;i++){
		int L=read()+1,R=read()+1;
		printf("%d\n",getMax(L,R));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
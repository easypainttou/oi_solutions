/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=15000+5;

//bool vis[maxn];
int T,n,L,W,tot,id[maxn];
double l[maxn],r[maxn];

bool com(int a,int b){
	return l[a]<l[b];
}

inline  double calLen(int R){
	return sqrt(R*R-W*W/4.0);
}

void solve(){
	scanf("%d",&T);
	while(T--){
		tot=0;
		scanf("%d%d%d",&n,&L,&W);
		for(int i=1;i<=n;i++){
			int pos,R;
			scanf("%d%d",&pos,&R);
			if(R<=W/2)continue;
			double len=calLen(R);
			l[++tot]=pos-len,r[tot]=pos+len;
			id[tot]=tot;
		}
		sort(id+1,id+1+tot,com);
		int cur=1,ans=0;
		double s=0,m=0;
		while(s<L){
			ans++;
			m=s;
			bool f=0;
			while(l[id[cur]]<=s&&cur<=tot){
				if(r[id[cur]]>m)f=1,m=r[id[cur]];
				++cur;
			}
			if(!f){
				printf("-1\n");
				goto no;
			}
			s=m;
		}
		printf("%d\n",ans);
		no:;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
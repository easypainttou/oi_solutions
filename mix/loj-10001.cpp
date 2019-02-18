/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e4+5;
const int maxm=5e3+5;
int n,h,id[maxm],b[maxm],e[maxm],t[maxm],ans,bk[maxn];

bool com(int a,int b){
	return e[a]<e[b];
}

void solve(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=h;i++){
		scanf("%d%d%d",b+i,e+i,t+i);
		id[i]=i;
	}
	sort(id+1,id+1+h,com);
	int ans=0;
	for(int i=1;i<=h;i++){
		int cnt=0;
		for(int j=b[id[i]];j<=e[id[i]];j++)
			if(bk[j])++cnt;
		if(cnt>=t[id[i]])continue;
		cnt=t[id[i]]-cnt;
		for(int j=e[id[i]];j>=b[id[i]];j--){
			if(!bk[j])bk[j]=1,--cnt,++ans;
			if(!cnt)break;
		}
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
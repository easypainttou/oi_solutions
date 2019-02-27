/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;

int n,id[maxn],s[maxn],f[maxn];

bool com(int a,int b){
	return f[a]<f[b];
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",s+i,f+i);
		id[i]=i;
	}
	sort(id+1,id+1+n,com);
	int st=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[id[i]]>=st){
			++ans,st=f[id[i]];
		}
	}
	printf("%d",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
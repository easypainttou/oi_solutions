#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3;
int val[maxn];

void getTree(int p){
	int v;
	scanf("%d",&v);
	if(v==-1)return;
	val[p]+=v;
	getTree(p-1);
	getTree(p+1);
}

void solve(){
	int v,cnt=0;
	while(scanf("%d",&v)){
		if(v==-1)break;
		++cnt;
		memset(val,0,sizeof(val));
		int pos=maxn/2;
		val[pos]+=v;
		getTree(pos-1);
		getTree(pos+1);
		int ans=0,p=0;
		while(!val[p])p++;
		printf("Case %d:\n",cnt);
		printf("%d",val[p++]);
		while(val[p])printf(" %d",val[p++]);
		printf("\n\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
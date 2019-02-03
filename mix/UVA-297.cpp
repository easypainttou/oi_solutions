#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1<<12;
const int lim=32;

int cnt,len,pos;
bool g[lim][lim];
char str[maxn];

void getTree(int x,int y,int px){
	++pos;
	//if(pos>=len)return;
	if(str[pos]=='p'){
		getTree(x,y+px/2,px/2);
		getTree(x,y,px/2);
		getTree(x+px/2,y,px/2);
		getTree(x+px/2,y+px/2,px/2);
	}else if(str[pos]=='f'){
		for(int i=x;i<x+px;i++)
			for(int j=y;j<y+px;j++)
				if(!g[i][j])g[i][j]=1,++cnt;
	}
}

void solve(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		cnt=0;
		memset(g,0,sizeof(g));
		
		pos=-1;
		gets(str);
		len=strlen(str);
		getTree(0,0,lim);
		//printf("There are %d black pixels.\n",cnt);
		
		pos=-1;
		gets(str);
		len=strlen(str);
		getTree(0,0,lim);
		
		printf("There are %d black pixels.\n",cnt);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
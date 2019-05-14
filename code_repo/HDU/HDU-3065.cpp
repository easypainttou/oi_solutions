/*
...
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;

const int MAXN=1e3+5;
const int MAXM=5e4+5;
const int TEXT=2e6+5;
const int NUM=26;

int n,cnt[MAXN];
char str[MAXN][55],str2[TEXT];

struct ac{
	int tot,rt,dic[MAXM][NUM],fail[MAXM],bk[MAXM];
	
	void init(){
		tot=0;
		rt=newNode();
	}
	
	int newNode(){
		for(int i=0;i<NUM;i++)dic[tot][i]=0;
		fail[tot]=bk[tot++]=0;
		return tot-1;
	}
	
	void insertStr(const int & id){
		int now=rt;
		for(int i=0;str[id][i];i++){
			int ch=str[id][i]-'A';
			if(!dic[now][ch])dic[now][ch]=newNode();
			now=dic[now][ch];
		}
		bk[now]=id;
	}
	
	void getFail(){
		queue<int>q;
		for(int i=0;i<NUM;i++){
			if(dic[rt][i])q.push(dic[rt][i]);
		}
		while(!q.empty()){
			int now=q.front();q.pop();
			for(int i=0;i<NUM;i++){
				if(dic[now][i])fail[dic[now][i]]=dic[fail[now]][i],q.push(dic[now][i]);
				else dic[now][i]=dic[fail[now]][i];
			}
		}
	}

	void getCnt(){
		int now=rt;
		for(int i=0;str2[i];i++){
			if(str2[i]<'A'||str2[i]>'Z'){
				now=rt;
				continue;
			}
			int ch=str2[i]-'A';
			now=dic[now][ch];
			for(int j=now;j;j=fail[j]){
				if(bk[j])cnt[bk[j]]++;
			}
		}
	}
	
}ac1;

void solve(){
	while(scanf("%d",&n)!=EOF){
		ac1.init();
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			cnt[i]=0;
			ac1.insertStr(i);
		}
		ac1.getFail();
		getchar(); //scanf后使用gets要先getchar读掉换行 qwq
		gets(str2);
		ac1.getCnt();
		for(int i=1;i<=n;i++){
			if(cnt[i])printf("%s: %d\n",str[i],cnt[i]);
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
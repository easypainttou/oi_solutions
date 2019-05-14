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

const int MAXN=1e5+5;
const int MAXM=1e4+5;
const int NUM=130;

int n,m,cnt;
char str[205],str2[MAXM];
set<int>ans;

struct ac{
	int tot,dic[MAXN][NUM],fail[MAXN],bk[MAXN];
	
	void insertStr(const int & id){
		int len=strlen(str),now=0;
		for(int i=0;i<len;i++){
			int ch=str[i];
			if(!dic[now][ch])dic[now][ch]=++tot;
			now=dic[now][ch];
		}
		bk[now]=id;
	}
	
	void getFail(){
		queue<int>q;
		while(!q.empty())q.pop();
		for(int i=0;i<NUM;i++){
			if(dic[0][i])fail[dic[0][i]]=0,q.push(dic[0][i]);
		}
		while(!q.empty()){
			int now=q.front();q.pop();
			for(int i=0;i<NUM;i++){
				if(dic[now][i])fail[dic[now][i]]=dic[fail[now]][i],q.push(dic[now][i]);
				else dic[now][i]=dic[fail[now]][i];
			}
		}
	}
	
	int getAns(){
		ans.clear();
		int res=0,len=strlen(str2),now=0;
		for(int i=0;i<len;i++){
			int ch=str2[i];
			now=dic[now][ch];
			for(int j=now;j;j=fail[j]){
				if(bk[j])ans.insert(bk[j]);
			}
		}
	}
}ac1;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",str),ac1.insertStr(i); //应该读一行的，然而scanf也过了？
	ac1.getFail();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",str2); //应该读一行的，然而scanf也过了？
		ac1.getAns();
		if(ans.size()){
			++cnt;
			printf("web %d:",i);
			for(set<int>::iterator it=ans.begin();it!=ans.end();it++)printf(" %d",*it);
			puts("");
		}
	}
	printf("total: %d\n",cnt); //这里要换行，否则PE qwq
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
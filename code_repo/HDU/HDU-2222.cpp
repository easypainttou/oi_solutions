/*

题目同loj-10057
AC自动机板子题 
然而一直TLE

解决方法
1.动态创建和删除结点
2.静态创建结点，然后每创建一个结点时清空上一次的数据
（然而还是T，这时把struct node数组分开成几个数组就卡过去了...）
QwQ？

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

const int MAXN=5e5+5;
const int MAXM=1e6+5;

char str[55],str2[MAXM];

struct ac{
	int tot,dic[MAXN][26],fail[MAXN],bk[MAXN]; //t的关键
	
	void init(){ //t的关键
		tot=0;
		newNode();
	}
	
	int newNode(){ //t的关键
		for(int j=0;j<26;j++)dic[tot][j]=0;
		fail[tot]=bk[tot++]=0;
		return tot-1;
	}
	
	void insertStr(){
		int now=0,len=strlen(str);
		for(int i=0;i<len;i++){
			int ch=str[i]-'a';
			if(!dic[now][ch])dic[now][ch]=newNode();
			now=dic[now][ch];
		}
		++bk[now];
	}
	
	void getFail(){
		queue<int>q;
		if(!q.empty())q.pop();
		for(int i=0;i<26;i++){
			if(dic[0][i])fail[dic[0][i]]=0,q.push(dic[0][i]);
		}
		while(!q.empty()){
			int now=q.front();q.pop();
			for(int i=0;i<26;i++){
				if(dic[now][i]){
					fail[dic[now][i]]=dic[fail[now]][i];
					q.push(dic[now][i]);
				}else{
					dic[now][i]=dic[fail[now]][i];
				}
			}
		}
	}
	
	int getAns(){
		int len=strlen(str2),now=0,res=0;
		for(int i=0;i<len;i++){
			int ch=str2[i]-'a';
			now=dic[now][ch];
			for(int j=now;j;j=fail[j]){
				res+=bk[j];
				bk[j]=0;
			}
		}
		return res;
	}
}ac1;

void solve(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		ac1.init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%s",str),ac1.insertStr();
		ac1.getFail();
		scanf("%s",str2);
		printf("%d\n",ac1.getAns());
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
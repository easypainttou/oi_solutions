/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=5e5+10;
const int maxm=1e6+10;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct node{
	int dic[26],fail,bk;
}ac[maxn];
char str[55],str2[maxm];
int T,n,tot;

void insertTrie(){
	int len=strlen(str),now=0;
	for(int i=0;i<len;i++){
		int c=str[i]-'a';
		if(ac[now].dic[c]==0)ac[now].dic[c]=++tot;
		now=ac[now].dic[c];
	}
	ac[now].bk++;
}

void getFail(){
	queue<int>q;
	for(int i=0;i<26;i++){
		if(ac[0].dic[i])ac[ac[0].dic[i]].fail=0,q.push(ac[0].dic[i]);
	}
	
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(ac[now].dic[i]){
				ac[ac[now].dic[i]].fail=ac[ac[now].fail].dic[i];
				q.push(ac[now].dic[i]);
			}
			else ac[now].dic[i]=ac[ac[now].fail].dic[i];
		}
	}
}

int getAns(){
	int now=0,ans=0,len=strlen(str2);
	for(int i=0;i<len;i++){
		int c=str2[i]-'a';
		now=ac[now].dic[c];
		for(int j=now;j;j=ac[j].fail){
			ans+=ac[j].bk;
			ac[j].bk=0;//wa...
		}
	}
	return ans;
}

void solve(){
	scanf("%d",&T);
	while(T--){
		tot=0;
		memset(ac,0,sizeof(ac));
		
		scanf("%d",&n);
		while(n--){
			scanf("%s",str);
			insertTrie();
		}
		getFail();
		scanf("%s",str2);
		printf("%d\n",getAns());
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
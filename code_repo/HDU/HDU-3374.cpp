#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const int MAXN=1e6+5;
const int MAXM=(1<<16)+5;
const int INF=0x3f3f3f3f;
const int MOD=10007;

char s[MAXN<<1];
int n,nxt[MAXN];

void preKmp(){
	int j=nxt[1]=0;
	for(int i=1;i<n;i++){
		while(j>0&&s[j+1]!=s[i+1])j=nxt[j];
		if(s[j+1]==s[i+1])j++;
		nxt[i+1]=j;
	}
}

int minPre(){
	int i=1,j=2,k;
	while(i<=n&&j<=n){
		for(k=0;k<n&&s[i+k]==s[j+k];k++);
		if(k==n)break;
		if(s[i+k]<s[j+k]){
			j=j+k+1;
			if(i==j)j++;
		}else{
			i=i+k+1;
			if(i==j)i++;
		}
	}
	return min(i,j);
}

int maxPre(){
	int i=1,j=2,k;
	while(i<=n&&j<=n){
		for(k=0;k<n&&s[i+k]==s[j+k];k++);
		if(k==n)break;
		if(s[i+k]<s[j+k]){
			i=i+k+1;
			if(i==j)i++;
		}else{
			j=j+k+1;
			if(i==j)j++;
		}
	}
	return min(i,j);
}

void solve(){
	while(~scanf("%s",s+1)){
		n=strlen(s+1);
		preKmp();
		int cnt=1;
		if(n%(n-nxt[n])==0)cnt=n/(n-nxt[n]);
		for(int i=1;i<=n;i++)s[n+i]=s[i];
		int mn=minPre(),mx=maxPre();
		printf("%d %d %d %d\n",mn,cnt,mx,cnt);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}

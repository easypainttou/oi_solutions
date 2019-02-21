/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=4e6+10;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

struct node{
	int dic[2],bk;
}trie[maxn];
int ans,n,a,tot;

void insertTrie(){
	int now=1;
	for(int i=30;i>=0;i--){
		int c=((a&(1<<i))?1:0);
		if(trie[now].dic[c]==0)trie[now].dic[c]=++tot;
		now=trie[now].dic[c];
	}
	trie[now].bk=a;
	
}

int findMax(){
	int now=1;
	for(int i=30;i>=0;i--){
		int c=((a&(1<<i))?1:0);
		if(trie[now].dic[1-c])now=trie[now].dic[1-c];
		else now=trie[now].dic[c];
	}
	return trie[now].bk^a;
}

void solve(){
	tot=1;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		insertTrie();
		ans=max(ans,findMax());
	}
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
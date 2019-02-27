/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

char str[maxn];
int next[maxn],n,ans[maxn],tot;

void kmp_pre(){
	int j=next[1]=0;
	for(int i=1;i<n;i++){
		while(j>0&&str[i+1]!=str[j+1])j=next[j];
		if(str[i+1]==str[j+1])j++;
		next[i+1]=j;
	}
}

void solve(){
	while(~scanf("%s",str+1)){
		tot=0;
		n=strlen(str+1);
		kmp_pre();
		ans[++tot]=n;
		int j=next[n];
		while(j>0){
			ans[++tot]=j;
			j=next[j];
		}
		for(int i=tot;i>=1;i--)printf("%d ",ans[i]);
		printf("\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
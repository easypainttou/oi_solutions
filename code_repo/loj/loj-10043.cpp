/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e3+10;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

char a[maxn],b[maxn];
int next[maxn],n,m;

void kmp_pre(){
	int j=next[1]=0;
	for(int i=1;i<m;i++){
		while(j>0&&b[i+1]!=b[j+1])j=next[j];
		if(b[i+1]==b[j+1])j++;
		next[i+1]=j;
	}
}

int kmp(){
	int ans=0,j=0;
	for(int i=0;i<n;i++){
		while(j>0&&b[j+1]!=a[i+1])j=next[j];
		if(b[j+1]==a[i+1])j++;
		if(j==m){
			ans++;
			j=0;
		}
	}
	return ans;
}

void solve(){
	while(1){
		scanf("%s",a+1);
		if(a[1]=='#'&&a[2]=='\0')break;
		scanf("%s",b+1);
		n=strlen(a+1),m=strlen(b+1);
		kmp_pre();
		printf("%d\n",kmp());
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
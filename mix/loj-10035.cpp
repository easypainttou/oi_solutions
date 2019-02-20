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
int next[maxn],n;

void kmp_pre(){
	int j=next[1]=0;
	for(int i=1;i<n;i++){
		while(j>0&&str[j+1]!=str[i+1])j=next[j];
		if(str[j+1]==str[i+1])j++;
		next[i+1]=j;
	}
}

void solve(){
	while(1){
		scanf("%s",str+1);
		if(str[1]=='.'&&str[2]=='\0')break;
		n=strlen(str+1);
		kmp_pre();
		if(n%(n-next[n])==0){
			printf("%d\n",n/(n-next[n]));
		}else{
			printf("1\n");
		}
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

ll hash[maxn],p[maxn],aha;
char str[maxn];
int n,ans,ap;

inline ll getHash(int l,int r){
	return (hash[r]-hash[l-1]*p[r-l+1]%mod+mod)%mod;
}


void solve(){
	scanf("%d%s",&n,str+1);
	if((n&1)==0){
		printf("NOT POSSIBLE");
		return;
	}
	p[0]=1;
	for(int i=1;i<=n;i++)hash[i]=(hash[i-1]*base+str[i]-'A'+1)%mod,p[i]=p[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		ll h1,h2;
		int pos;
		if(i<=n/2+1){
			h1=(getHash(1,i-1)*p[n/2-i+1]%mod+getHash(i+1,n/2+1))%mod,h2=getHash(n/2+2,n);
			pos=n/2+2;
		}
		else{
			h1=getHash(1,n/2),h2=(getHash(n/2+1,i-1)*p[n-i]%mod+getHash(i+1,n))%mod;
			pos=1;
		}
		if(h1==h2){
			if(ans==0)aha=h1,ap=pos,ans++;
			else if(h1!=aha){
				printf("NOT UNIQUE\n");
				return;
			}
		}
	}
	if(!ans){printf("NOT POSSIBLE");return;}
	for(int i=ap;i<=ap+n/2-1;i++){
		putchar(str[i]);
	}
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
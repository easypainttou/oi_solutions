/*
//使用kmp

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const double eps=1e-10;

int next[maxn],n,m;
char a[maxn],b[maxn];

void kmp_pre(){
	int j=next[1]=0;
	for(int i=1;i<m;i++){
		while(j>0&&b[i+1]!=b[j+1])j=next[j];
		if(b[i+1]==b[j+1])j++;
		next[i+1]=j;
	}
}

int kmp(){
	int ans=0;
	for(int j=0,i=0;i<n;i++){
		while(j>0&&b[j+1]!=a[i+1])j=next[j];
		if(b[j+1]==a[i+1])j++;
		if(j==m){
			j=next[j];
			ans++;
		}
	}
	return ans;
}

void solve(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	kmp_pre();
	printf("%d",kmp());
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
*/



//使用hash


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,m,ans;
ll ah[maxn],bh,p[maxn];
char a[maxn],b[maxn];

void solve(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	p[0]=1;
	for(int i=1;i<=n;i++)ah[i]=(ah[i-1]*base+a[i]-'A'+1)%mod,p[i]=p[i-1]*base%mod;
	for(int i=1;i<=m;i++)bh=(bh*base+b[i]-'A'+1)%mod;
	for(int i=1;i+m-1<=n;i++)if(bh==(ah[i+m-1]-(ll)ah[i-1]*p[m]%mod+mod)%mod)ans++;
	printf("%d",ans);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
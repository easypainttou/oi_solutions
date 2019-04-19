/*
...
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=200+10;
const int MAXM=(1<<9)+10;

struct hP{
	int a[MAXN],len;
	
	hP(int len=0):len(len){
		memset(a,0,sizeof(a));
	}
	
	void mulNum(const int &x){
		for(int i=0;i<len;i++){
			a[i]*=x;
		}
		for(int i=0;i<len;i++){
			a[i+1]+=a[i]/10;
			a[i]%=10;
			if(a[len])++len;
		}
	}
	
	void add(const hP&tmp){
		len=max(tmp.len,len);
		for(int i=0;i<len;i++){
			a[i]+=tmp.a[i];
		}
		for(int i=0;i<len;i++){
			a[i+1]+=a[i]/10;
			a[i]%=10;
			if(a[len])++len;
		}
	}
	
	void output(){
		for(int i=len-1;i>=0;i--)printf("%d",a[i]);
	}
	
}ans;
int k,w,nume[MAXM],deno[MAXM];

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

void calC(int a,int b){
	if(a<b)return;
	for(int i=1;i<=b;i++)nume[i]=a-i+1,deno[i]=i;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b;j++){
			int d=gcd(nume[j],deno[i]);
			nume[j]/=d,deno[i]/=d;
			if(deno[i]==1)break;
		}
	}
	hP tmp(1);
	tmp.a[0]=1;
	for(int i=1;i<=b;i++){
		tmp.mulNum(nume[i]);
	}
	ans.add(tmp);
}

void solve(){
	scanf("%d%d",&k,&w);
	int len=w/k,r=(1<<w%k)-1,x=(1<<k)-1;
	for(int i=2;i<=len;i++)calC(x,i);
	for(int i=1;i<=r;i++)calC(x-i,len);
	ans.output();
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
/*
找规律...qwq
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int maxm=62;
const int inf=0x3f3f3f3f;

ll t,p[64];
int n,flag,a[2][maxn];

void solve(){
	p[0]=1;
	for(int i=1;i<64;i++)p[i]=p[i-1]<<1;
	scanf("%d%lld",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&a[0][i<<1]);
		--a[0][i<<1];
	}
	for(int i=1;i<60;i++){
		if(p[i]&t){
			flag^=1;
			for(int j=0;j<n;j++){
				a[flag][j<<1]=a[flag^1][(((j-p[i-1])%n+n)%n)<<1]^a[flag^1][(((j+p[i-1])%n+n)%n)<<1];
			}
		}
	}
	if(t&1){
		flag^=1;
		for(int i=0;i<2*n;i++){
			if(i&1)a[flag][i]=a[flag^1][(i-1)%(2*n)]^a[flag^1][(i+1)%(2*n)];
			else a[flag][i]=0;
			printf("%d ",a[flag][i]+(i&1?1:0));
		}

	}else{
		for(int i=0;i<2*n;i++){
			printf("%d ",a[flag][i]+(i&1?0:1));
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
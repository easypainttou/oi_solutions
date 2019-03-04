/*
...
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int maxm=1e3+5;
const int inf=0x3f3f3f3f;
typedef long long ll;

int n,g[20][20],f[1<<20][20];

void hamilton(){
	memset(f,0x3f,sizeof(f));
	f[1][0]=0;
	for(int i=0;i<1<<n;i++){
		for(int j=0;j<n;j++){
			if(i>>j&1){
				for(int k=0;k<n;k++){
					int stt=i^1<<j;
					if(stt>>k&1){
						f[i][j]=min(f[i][j],f[stt][k]+g[k][j]);
					}
				}
			}
		}
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	hamilton();
	printf("%d",f[(1<<n)-1][n-1]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
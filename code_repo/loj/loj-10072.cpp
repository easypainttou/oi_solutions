/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=105;
const int maxm=105;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,m,g[maxn][maxn],d[maxn][maxn],path[maxn][maxn];
vector<int>ap;

void getPath(int i,int j){
	int now=path[i][j];
	if(now==0)return;
	getPath(i,now);
	ap.push_back(now);
	getPath(now,j);
}

void floyd(){
	int ans=inf;
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				if(ans>(ll)d[i][j]+g[j][k]+g[k][i]){
					ans=d[i][j]+g[j][k]+g[k][i];
					ap.clear();
					ap.push_back(i);
					getPath(i,j);
					ap.push_back(j);
					ap.push_back(k);
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					path[i][j]=k;
				}
			}
		}
	}
}

void solve(){
	int x,y,z;
	memset(g,0x3f,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[y][x]=g[x][y]=min(g[x][y],z);
	}
	memcpy(d,g,sizeof(g));
	floyd();
	if(ap.size()==0)printf("No solution.");
	else for(int i=0;i<ap.size();i++)printf("%d ",ap[i]);
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
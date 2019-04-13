/*
...
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=70;
const int maxm=15;
const int inf=0x3f3f3f3f;

ll n,m,t,act,N,insM[maxn],tmpf[maxn],f[maxn],len[maxm],pos[maxm][maxm];
char insS[maxm][maxm],tmpstr[maxm];

struct matrix{
	ll a[maxn][maxn];
	matrix(){
		memset(a,0,sizeof(a)); //注意初始化qwq
	}
	matrix operator*(const matrix&A){
		matrix tmp;
		for(ll i=0;i<=N;i++){
			for(ll j=0;j<=N;j++){
				for(ll k=0;k<=N;k++){
					tmp.a[i][k]+=a[i][j]*A.a[j][k];
				}
			}
		}
		return tmp;
	}
}aS[maxn],a60;

void mulF(const matrix&a){
	memset(tmpf,0,sizeof(tmpf));
	for(ll i=0;i<=N;i++){
		for(ll j=0;j<=N;j++){
			tmpf[i]+=(ll)a.a[i][j]*f[j];
		}
	}
	memcpy(f,tmpf,sizeof(f));
}

void qPow(matrix a,ll b){
	matrix res;
	for(ll i=0;i<=N;i++)res.a[i][i]=1;
	while(b){
		if(b&1)res=res*a;
		a=a*a;
		b>>=1;
	}
	mulF(res);
}

void getMatrix(){
	for(ll k=0;k<60;k++){
		aS[k].a[0][0]=1;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++){
				ll insNow=insM[pos[i][j]];
				char insId=insS[insNow][k%len[insNow]];
				if(insId>='0'&&insId<='9')aS[k].a[pos[i][j]][0]=insId-'0',aS[k].a[pos[i][j]][pos[i][j]]=1;
				else if(insId=='N'&&i-1>=1)aS[k].a[pos[i-1][j]][pos[i][j]]=1;
				else if(insId=='W'&&j-1>=1)aS[k].a[pos[i][j-1]][pos[i][j]]=1;
				else if(insId=='S'&&i+1<=n)aS[k].a[pos[i+1][j]][pos[i][j]]=1;
				else if(insId=='E'&&j+1<=m)aS[k].a[pos[i][j+1]][pos[i][j]]=1;
			}
		}
	}
	for(ll i=0;i<=N;i++)a60.a[i][i]=1;
	for(ll k=59;k>=0;k--)a60=a60*aS[k]; //没注意矩阵乘法顺序wa了，qwq
}

void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&t,&act);N=n*m;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)pos[i][j]=n*(i-1)+j;
	for(ll i=1;i<=n;i++){
		scanf("%s",tmpstr+1);
		for(ll j=1;j<=m;j++)insM[pos[i][j]]=tmpstr[j]-'0';
	}
	for(ll i=0;i<act;i++){
		scanf("%s",insS[i]);
		len[i]=strlen(insS[i]);
	}
	getMatrix();
	ll t1=t/60,t2=t%60;
	f[0]=1,qPow(a60,t1);
	for(ll i=1;i<=t2;i++)mulF(aS[i-1]);
	ll ans=0;
	for(ll i=1;i<=N;i++)ans=max(ans,f[i]);
	printf("%lld",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
/*

数位dp 板子题
f[i][j] ：高度为i的完全二叉树二进制表示（不包含根结点）中有j个1的个数

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=30+10;
const int INF=0x3f3f3f3f;

int x,y,k,b,f[MAXN][MAXN],tmp[MAXN];

inline void init(){
	f[0][0]=1;
	for(int i=1;i<=32;i++){
		f[i][0]=1;
		for(int j=1;j<=i-1;j++){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
}

int calc(int num,int ones){
	int cnt=0,res=0;
	for(int i=31;i>=1;i--){
		if(num&(1<<i)){
			++cnt;
			num^=1<<i;
		}
		if(num&(1<<i-1)){
			res+=f[i][ones-cnt];
		}
	}
	if(num+cnt==ones)++res;
	return res;
}

int trans(int num,int b){
	int p=0;
	while(num){
		tmp[++p]=num%b;
		num/=b;
	}
	int i;
	for(i=p;i>=1;i--){
		if(tmp[i]>1)break;
	}
	for(;i>=1;i--){
		tmp[i]=1;
	}
	int res=0;
	for(int i=1;i<=p;i++){
		res+=tmp[i]*(1<<i-1);
	}
	return res;
}

void solve(){
	init();
	scanf("%d%d%d%d",&x,&y,&k,&b);
	printf("%d",calc(trans(y,b),k)-calc(trans(x-1,b),k));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
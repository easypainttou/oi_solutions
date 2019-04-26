/*
sum=a+b+c+d+(p>0)+(q>0)
递推方程为
dp[a][b][c][d][p][q]=
(a<13)*(13-a)/(54-sum)*dp[a+1][b][c][d][p][q]
+(b<13)*(13-b)/(54-sum)*dp[a][b+1][c][d][p][q]
+(c<13)*(13-c)/(54-sum)*dp[a][b][c+1][d][p][q]
+(d<13)*(13-d)/(54-sum)*dp[a][b][c][d+1][p][q]
+(p==0)*1/(54-sum)*min(dp[a][b][c][d][p=1~4][q])
+(q==0)*1/(54-sum)*min(dp[a][b][c][d][p][q=1~4])
+1

dfs，并且要用记忆化搜索
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=15;
const int MAXN=2e3+10;
const int MAXM=30;
const int INF=0x3f3f3f3f;

int A,B,C,D;
double ans,dp[N][N][N][N][5][5];

double dfs(int a,int b,int c,int d,int p,int q){
	if(dp[a][b][c][d][p][q])return dp[a][b][c][d][p][q];
	int x[5]={0,a,b,c,d},sum=a+b+c+d;
	for(int i=1;i<=4;i++){
		if(p==i)++x[i],++sum;
		if(q==i)++x[i],++sum;
	}
	if(x[1]>=A&&x[2]>=B&&x[3]>=C&&x[4]>=D)return 0;
	if(sum>=54)return dp[a][b][c][d][p][q]=INF; //无解的时候，终止状态都是INF，于是最后期望就大于等于INF，qwq
	int rem=54-sum;
	dp[a][b][c][d][p][q]=1;
	if(a<13)dp[a][b][c][d][p][q]+=(13.0-a)/rem*dfs(a+1,b,c,d,p,q);
	if(b<13)dp[a][b][c][d][p][q]+=(13.0-b)/rem*dfs(a,b+1,c,d,p,q);
	if(c<13)dp[a][b][c][d][p][q]+=(13.0-c)/rem*dfs(a,b,c+1,d,p,q);
	if(d<13)dp[a][b][c][d][p][q]+=(13.0-d)/rem*dfs(a,b,c,d+1,p,q);
	if(!p){
		double mn=INF;
		for(int i=1;i<=4;i++)mn=min(mn,dfs(a,b,c,d,i,q));
		dp[a][b][c][d][p][q]+=1.0/rem*mn;
	}
	if(!q){
		double mn=INF;
		for(int i=1;i<=4;i++)mn=min(mn,dfs(a,b,c,d,p,i));
		dp[a][b][c][d][p][q]+=1.0/rem*mn;
	}
	return dp[a][b][c][d][p][q];
}

void solve(){
	scanf("%d%d%d%d",&A,&B,&C,&D);
	ans=dfs(0,0,0,0,0,0);
	if(ans>=INF)ans=-1;
	printf("%.3lf",ans);
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
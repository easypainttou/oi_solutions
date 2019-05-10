/*

数位dp

dfs，需要记忆化搜索

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10+5;
const int INF=0x3f3f3f3f;

int digit[MAXN],f[MAXN][MAXN][2];

int dfs(int pos,int last,int flag){
	if(pos==0)return 1;
	if(~f[pos][last][flag])return f[pos][last][flag];
	int res=0,end=flag?digit[pos]:9;
	for(int i=0;i<=end;i++){
		if(abs(i-last)<2)continue;
		if(last==11&&i==0)res+=dfs(pos-1,11,flag&&i==end);
		else res+=dfs(pos-1,i,flag&&i==end);
	}
	return f[pos][last][flag]=res;
}

int getNum(int x){
	int cnt=0;
	while(x){
		digit[++cnt]=x%10;
		x/=10;
	}
	memset(f,0xff,sizeof(f));
	return dfs(cnt,11,1);
}

void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",getNum(b)-getNum(a-1));
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
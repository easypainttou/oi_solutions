/*

数位dp

dfs，不用记忆化搜索也可以过qwq

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=10+5;
const int INF=0x3f3f3f3f;

int digit[MAXN];

//考虑到pos位，上一位选择了last，flag是用来防止超过getNum中的x的，返回方案数 qwq
int dfs(int pos,int last,int flag){
	if(pos==0)return 1;
	int res=0,end=flag?digit[pos]:9;
	for(int i=last;i<=end;i++){
		res+=dfs(pos-1,i,flag&&i==end);
	}
	return res;
}

int getNum(int x){
	int cnt=0;
	while(x){
		digit[++cnt]=x%10;
		x/=10;
	}
	return dfs(cnt,0,1);
}

void solve(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		printf("%d\n",getNum(b)-getNum(a-1));
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
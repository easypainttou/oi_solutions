/*
bash博弈 板子
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>

using namespace std;

typedef long long ll;

const int MAXN=100+10;
const int MAXM=5;
const int INF=0x3f3f3f3f;

int n,k;

void solve(){
	scanf("%d%d",&n,&k);
	if(n%(k+1))puts("1");
	else puts("2");
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
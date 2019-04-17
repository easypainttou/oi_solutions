/*
nim博弈 板子
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

int tmp,n,sum;

void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&tmp),sum^=tmp;
	if(sum)puts("win");
	else puts("lose");
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
	return 0;
}
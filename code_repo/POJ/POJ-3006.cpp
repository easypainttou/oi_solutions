#include<cstdio>
#include<cstring>
//#include<iostream>

using namespace std;
const int MAXN=1e6+10;
bool bk[MAXN];
int pri[MAXN],pc;

void getPrime(){
	bk[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!bk[i])pri[pc++]=i;
		for(int j=0;j<pc;j++){
			if(i*pri[j]>=MAXN)break;
			bk[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}

void solve(){
	getPrime();
	int a,d,n,cnt,i;
	while(1){
		scanf("%d%d%d",&a,&d,&n);
		if(a==0&&d==0&&n==0)break;
		cnt=0;
		for(i=a;cnt<n;i+=d){
			if(!bk[i])cnt++;
		}
		printf("%d\n",i-d);
	}
}

int main(){
	//freopen("out","w",stdout);
	solve();
	return 0;
}
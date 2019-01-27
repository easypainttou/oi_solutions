#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const int MAXN=1e9;
const int N=2e3;
ll tab[N],cnt;

void getTab(){
	for(ll i=1;i<=MAXN;i*=2){
		for(ll j=1;i*j<=MAXN;j*=3){
			for(ll k=1;i*j*k<=MAXN;k*=5){
				tab[cnt++]=i*j*k;
				//cout<<i*j*k<<endl;
			}
		}
	}
	//cout<<cnt;
	sort(tab,tab+cnt);
	/*
	for(int i=0;i<cnt;i++){
		cout<<tab[i]<<" ";
	}
	*/
}

void solve(){
	getTab();
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",tab[n-1]);
	}
	
}

int main(){
	//freopen("out","w",stdout);
	solve();
	//getTab();
	return 0;
}
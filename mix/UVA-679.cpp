#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;

void solve(){
	int l,d,i,t;
	scanf("%d",&l);
	while(l--){
		t=1;
		scanf("%d%d",&d,&i);
		for(int j=1;j<d;j++){
			if(i&1)t=2*t,i=(i+1)/2;
			else t=2*t+1,i=i/2;
		}
		printf("%d\n",t);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
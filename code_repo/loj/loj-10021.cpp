#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int dep,n,a[maxn];

bool dfs(int step){ 
	if(step==dep){
		if(a[dep]==n){
			for(int i=1;i<=dep;i++){
				printf("%d ",a[i]);
			}
			puts("");
			return 1;
		}
		return 0;
	}
	for(int i=step;i>=1;--i){
		for(int j=i;j<=step;j++){
			if(a[i]+a[j]>n)break;
			if(a[i]+a[j]<=a[step])continue;
			a[step+1]=a[i]+a[j];
			if(dfs(step+1))return 1;			
		}
	}
	return 0; 
}

void solve(){
	a[1]=1;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(int i=1;;i++){
			dep=i;
			if(dfs(1))break;
		}
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
} 
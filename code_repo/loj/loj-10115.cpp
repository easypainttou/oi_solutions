/*
...
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int maxn=5e4+5;
const int maxm=4e4+5;
const double eps=1e-10;
const int base=131;
const int mod=1e9+7;

int n,m,l[maxn],r[maxn];

inline int lowbit(int x){return x&(-x);}

void add(int arr[],int x){
	while(x<=n){
		++arr[x];
		x+=lowbit(x);
	}
}

int query(int arr[],int x){
	int ans=0;
	while(x>=1){
		ans+=arr[x];
		x-=lowbit(x);
	}
	return ans;
}

void solve(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			add(l,y),add(r,z);	
		}else{
			printf("%d\n",query(l,z)-query(r,y-1));
		}
	}
	
}

int main(){
//	freopen("in.txt","r",stdin);
	solve();
	return 0;
}
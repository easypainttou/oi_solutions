/*
...
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e3+5;

int n,a[maxn],b[maxn],m[maxn],id[maxn],pos[maxn],ac,bc;

bool com1(int a,int b){
	return m[a]<m[b];
}

bool com2(int a,int b){
	return m[a]>m[b];
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=1;i<=n;i++)if(a[i]<b[i])m[++ac]=a[i],pos[ac]=ac,id[ac]=i;
	for(int i=1;i<=n;i++)if(a[i]>=b[i])m[++bc+ac]=b[i],pos[bc+ac]=bc+ac,id[bc+ac]=i;
	sort(pos+1,pos+ac+1,com1),sort(pos+ac+1,pos+ac+bc+1,com2);
	int aans=0,bans=0;
	for(int i=1;i<=n;i++){
		int cur=id[pos[i]];
		aans+=a[cur];
		if(bans<aans)bans=aans;
		bans+=b[cur];
	}
	printf("%d\n",bans);
	for(int i=1;i<=n;i++){
		printf("%d",id[pos[i]]);
		if(i!=n)printf(" ");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e4+10;

bool read(int & w){
	bool f1=1,f2=1;
	int w1,d1,w2,d2;
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
	
	if(!w1)f1=read(w1);
	if(!w2)f2=read(w2);
	w=w1+w2;
	return f1&&f2&&(w1*d1==w2*d2);
}

void solve(){
	int t,w;
	scanf("%d",&t);
	while(t--){
		if(read(w))printf("YES\n");
		else printf("NO\n");
		if(t)printf("\n");
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	solve();
	return 0;
}